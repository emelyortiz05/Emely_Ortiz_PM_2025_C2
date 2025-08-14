#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// PROYECTO FINAL - Gestion de gastos por kilometros

#define MAX_VEHICULOS 100

typedef enum {
    COMBUSTIBLE_GASOLINA = 1,
    COMBUSTIBLE_GASOIL = 2
} TipoCombustible;

typedef struct {
    char placa[16];
    char marca[32];
    char modelo[32];
    TipoCombustible tipo_combustible; // 1 gasolina, 2 gasoil
    double km_x_galon_carretera;
    double km_x_galon_ciudad;
    double costo_gomas;            // costo del juego de gomas
    double km_gomas;               // vida util de las gomas en km
    double costo_seguro_12m;       // costo del seguro por 12 meses
    double costo_mantenimiento;    // costo de cada mantenimiento
    double km_mantenimiento;       // cada cuantos km se hace ese mantenimiento
    double costo_vehiculo;         // precio del vehiculo
    double vida_util_km;           // vida util del vehiculo en km
    double km_por_agno_promedio;   // kilometros por agno promedio (para prorratear seguro)
} Vehiculo;

typedef struct {
    double costo_gasolina_por_galon;
    double costo_gasoil_por_galon;
} DatosGenerales;

//Utilidades IO
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void leer_cadena(const char* prompt, char* destino, size_t tam) {
    printf("%s", prompt);
    if (fgets(destino, (int)tam, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    size_t n = strlen(destino);
    if (n > 0 && destino[n-1] == '\n') destino[n-1] = '\0';
}

int leer_entero(const char* prompt) {
    int v; int ok = 0;
    do {
        printf("%s", prompt);
        if (scanf("%d", &v) == 1) { ok = 1; }
        else { printf("Entrada invalida. Intente de nuevo.\n"); }
        limpiar_buffer();
    } while (!ok);
    return v;
}

double leer_double(const char* prompt) {
    double v; int ok = 0;
    do {
        printf("%s", prompt);
        if (scanf("%lf", &v) == 1) { ok = 1; }
        else { printf("Entrada invalida. Intente de nuevo.\n"); }
        limpiar_buffer();
    } while (!ok);
    return v;
}

//Gestion de vehiculos

int buscar_vehiculo_por_placa(Vehiculo* lista, int n, const char* placa) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(lista[i].placa, placa) == 0) return i;
    }
    return -1;
}

void listar_vehiculos(Vehiculo* lista, int n) {
    if (n == 0) { printf("No hay vehiculos registrados.\n"); return; }
    printf("\n==== Lista de vehiculos (%d) ====\n", n);
    for (int i = 0; i < n; ++i) {
        Vehiculo *v = &lista[i];
        printf("%2d) %s | %s %s | Comb: %s | Carretera: %.2f km/gal | Ciudad: %.2f km/gal\n",
               i+1,
               v->placa,
               v->marca,
               v->modelo,
               (v->tipo_combustible == COMBUSTIBLE_GASOLINA ? "Gasolina" : "Gasoil"),
               v->km_x_galon_carretera,
               v->km_x_galon_ciudad);
    }
}

void crear_vehiculo(Vehiculo* lista, int* n_ptr) {
    int n = *n_ptr;
    if (n >= MAX_VEHICULOS) { printf("Capacidad maxima alcanzada.\n"); return; }

    Vehiculo v;
    leer_cadena("Placa: ", v.placa, sizeof(v.placa));
    if (buscar_vehiculo_por_placa(lista, n, v.placa) != -1) {
        printf("Ya existe un vehiculo con esa placa.\n");
        return;
    }
    leer_cadena("Marca: ", v.marca, sizeof(v.marca));
    leer_cadena("Modelo: ", v.modelo, sizeof(v.modelo));

    int tc;
    do {
        tc = leer_entero("Tipo combustible (1=Gasolina, 2=Gasoil): ");
    } while (tc != 1 && tc != 2);
    v.tipo_combustible = (tc == 1) ? COMBUSTIBLE_GASOLINA : COMBUSTIBLE_GASOIL;

    v.km_x_galon_carretera = leer_double("Km por galon en carretera: ");
    v.km_x_galon_ciudad    = leer_double("Km por galon en ciudad: ");
    v.costo_gomas          = leer_double("Costo gomas (juego completo): ");
    v.km_gomas             = leer_double("Km de vida util de gomas: ");
    v.costo_seguro_12m     = leer_double("Costo de seguro por 12 meses: ");
    v.costo_mantenimiento  = leer_double("Costo de cada mantenimiento: ");
    v.km_mantenimiento     = leer_double("Cada cuantos km se hace mantenimiento: ");
    v.costo_vehiculo       = leer_double("Costo del vehiculo: ");
    v.vida_util_km         = leer_double("Vida util del vehiculo en km: ");
    v.km_por_agno_promedio = leer_double("Km por agno promedio: ");

    lista[n] = v;
    *n_ptr = n + 1;
    printf("Vehiculo creado correctamente.\n");
}

void borrar_vehiculo(Vehiculo* lista, int* n_ptr) {
    if (*n_ptr == 0) { printf("No hay vehiculos.\n"); return; }
    char placa[16];
    leer_cadena("Ingrese placa a borrar: ", placa, sizeof(placa));
    int idx = buscar_vehiculo_por_placa(lista, *n_ptr, placa);
    if (idx == -1) { printf("No existe vehiculo con esa placa.\n"); return; }
    for (int i = idx; i < *n_ptr - 1; ++i) lista[i] = lista[i+1];
    (*n_ptr)--;
    printf("Vehiculo borrado.\n");
}

void modificar_vehiculo(Vehiculo* lista, int n) {
    if (n == 0) { printf("No hay vehiculos.\n"); return; }
    char placa[16];
    leer_cadena("Ingrese placa a modificar: ", placa, sizeof(placa));
    int idx = buscar_vehiculo_por_placa(lista, n, placa);
    if (idx == -1) { printf("No existe vehiculo con esa placa.\n"); return; }

    Vehiculo *v = &lista[idx];

    printf("Modificando vehiculo %s (%s %s)\n", v->placa, v->marca, v->modelo);

    char tmp[64];
    leer_cadena("Nueva marca (enter para mantener): ", tmp, sizeof(tmp));
    if (strlen(tmp) > 0) strncpy(v->marca, tmp, sizeof(v->marca)-1), v->marca[sizeof(v->marca)-1]='\0';

    leer_cadena("Nuevo modelo (enter para mantener): ", tmp, sizeof(tmp));
    if (strlen(tmp) > 0) strncpy(v->modelo, tmp, sizeof(v->modelo)-1), v->modelo[sizeof(v->modelo)-1]='\0';

    printf("Tipo combustible actual: %s\n", v->tipo_combustible==COMBUSTIBLE_GASOLINA?"Gasolina":"Gasoil");
    printf("Ingrese 1=Gasolina, 2=Gasoil, 0=mantener: ");
    int tc; if (scanf("%d", &tc) == 1) {
        limpiar_buffer();
        if (tc==1 || tc==2) v->tipo_combustible = (tc==1)?COMBUSTIBLE_GASOLINA:COMBUSTIBLE_GASOIL;
    } else { limpiar_buffer(); }

    printf("Km/gal carretera actual: %.2f. Ingrese nuevo (negativo para mantener): ", v->km_x_galon_carretera);
    double d; if (scanf("%lf", &d)==1) { if (d>=0) v->km_x_galon_carretera = d; } limpiar_buffer();

    printf("Km/gal ciudad actual: %.2f. Ingrese nuevo (negativo para mantener): ", v->km_x_galon_ciudad);
    if (scanf("%lf", &d)==1) { if (d>=0) v->km_x_galon_ciudad = d; } limpiar_buffer();

    printf("Costo gomas actual: %.2f. Nuevo (negativo para mantener): ", v->costo_gomas);
    if (scanf("%lf", &d)==1) { if (d>=0) v->costo_gomas = d; } limpiar_buffer();

    printf("Km gomas actual: %.2f. Nuevo (negativo para mantener): ", v->km_gomas);
    if (scanf("%lf", &d)==1) { if (d>=0) v->km_gomas = d; } limpiar_buffer();

    printf("Costo seguro 12m actual: %.2f. Nuevo (negativo para mantener): ", v->costo_seguro_12m);
    if (scanf("%lf", &d)==1) { if (d>=0) v->costo_seguro_12m = d; } limpiar_buffer();

    printf("Costo mantenimiento actual: %.2f. Nuevo (negativo para mantener): ", v->costo_mantenimiento);
    if (scanf("%lf", &d)==1) { if (d>=0) v->costo_mantenimiento = d; } limpiar_buffer();

    printf("Km mantenimiento actual: %.2f. Nuevo (negativo para mantener): ", v->km_mantenimiento);
    if (scanf("%lf", &d)==1) { if (d>=0) v->km_mantenimiento = d; } limpiar_buffer();

    printf("Costo vehiculo actual: %.2f. Nuevo (negativo para mantener): ", v->costo_vehiculo);
    if (scanf("%lf", &d)==1) { if (d>=0) v->costo_vehiculo = d; } limpiar_buffer();

    printf("Vida util km actual: %.2f. Nuevo (negativo para mantener): ", v->vida_util_km);
    if (scanf("%lf", &d)==1) { if (d>=0) v->vida_util_km = d; } limpiar_buffer();

    printf("Km por agno promedio actual: %.2f. Nuevo (negativo para mantener): ", v->km_por_agno_promedio);
    if (scanf("%lf", &d)==1) { if (d>=0) v->km_por_agno_promedio = d; } limpiar_buffer();

    printf("Vehiculo modificado.\n");
}

//Gestion de datos generales
void mostrar_datos_generales(const DatosGenerales* dg) {
    printf("Costo gasolina por galon: %.2f\n", dg->costo_gasolina_por_galon);
    printf("Costo gasoil por galon : %.2f\n", dg->costo_gasoil_por_galon);
}

void editar_datos_generales(DatosGenerales* dg) {
    dg->costo_gasolina_por_galon = leer_double("Nuevo costo gasolina por galon: ");
    dg->costo_gasoil_por_galon   = leer_double("Nuevo costo gasoil por galon: ");
    printf("Datos generales actualizados.\n");
}

//Calculo de costos de viaje

typedef struct {
    double costo_gomas_total;
    double costo_seguro_total;
    double costo_combustible_total;
    double costo_mantenimiento_total;
    double costo_vehiculo_total; // depreciacion
    double costo_total;
    double costo_por_km;
} ResultadoViaje;

ResultadoViaje calcular_viaje(const Vehiculo* v, const DatosGenerales* dg, double km_totales, double porcentaje_ciudad) {
    ResultadoViaje r = {0};

    if (km_totales <= 0) return r;
    if (porcentaje_ciudad < 0) porcentaje_ciudad = 0;
    if (porcentaje_ciudad > 100) porcentaje_ciudad = 100;

    double km_ciudad = km_totales * (porcentaje_ciudad / 100.0);
    double km_carretera = km_totales - km_ciudad;

    // Combustible
    double gal_ciudad = (v->km_x_galon_ciudad > 0) ? (km_ciudad / v->km_x_galon_ciudad) : 0.0;
    double gal_carre  = (v->km_x_galon_carretera > 0) ? (km_carretera / v->km_x_galon_carretera) : 0.0;
    double gal_total = gal_ciudad + gal_carre;

    double precio_galon = (v->tipo_combustible == COMBUSTIBLE_GASOLINA) ? dg->costo_gasolina_por_galon
                                                                        : dg->costo_gasoil_por_galon;
    r.costo_combustible_total = gal_total * precio_galon;

    // Gomas: prorrateo por km
    double costo_gomas_por_km = (v->km_gomas > 0) ? (v->costo_gomas / v->km_gomas) : 0.0;
    r.costo_gomas_total = costo_gomas_por_km * km_totales;

    // Seguro: prorrateo por km usando km por agno promedio
    double costo_seguro_por_km = (v->km_por_agno_promedio > 0) ? (v->costo_seguro_12m / v->km_por_agno_promedio) : 0.0;
    r.costo_seguro_total = costo_seguro_por_km * km_totales;

    // Mantenimiento: prorrateo por km
    double costo_mant_por_km = (v->km_mantenimiento > 0) ? (v->costo_mantenimiento / v->km_mantenimiento) : 0.0;
    r.costo_mantenimiento_total = costo_mant_por_km * km_totales;

    // Vehiculo (depreciacion) por km basado en vida util
    double dep_por_km = (v->vida_util_km > 0) ? (v->costo_vehiculo / v->vida_util_km) : 0.0;
    r.costo_vehiculo_total = dep_por_km * km_totales;

    r.costo_total = r.costo_gomas_total + r.costo_seguro_total + r.costo_combustible_total +
                    r.costo_mantenimiento_total + r.costo_vehiculo_total;
    r.costo_por_km = r.costo_total / km_totales;

    return r;
}

void flujo_calculo_viaje(Vehiculo* lista, int n, const DatosGenerales* dg) {
    if (n == 0) { printf("Primero cree al menos un vehiculo.\n"); return; }

    listar_vehiculos(lista, n);
    int opcion = leer_entero("Seleccione numero de vehiculo: ");
    if (opcion < 1 || opcion > n) { printf("Seleccion invalida.\n"); return; }
    Vehiculo *v = &lista[opcion-1];

    double km = leer_double("Kilometros del viaje: ");
    double pct_ciudad = leer_double("Porcentaje de km en ciudad (0-100): ");

    ResultadoViaje r = calcular_viaje(v, dg, km, pct_ciudad);

    printf("\n===== Resultado desglosado =====\n");
    printf("Vehiculo: %s | %s %s | Comb: %s\n", v->placa, v->marca, v->modelo,
           v->tipo_combustible==COMBUSTIBLE_GASOLINA?"Gasolina":"Gasoil");
    printf("Distancia total: %.2f km (Ciudad %.2f%%)\n", km, pct_ciudad);
    printf("Costo de gomas: %.2f\n", r.costo_gomas_total);
    printf("Costo de seguro: %.2f\n", r.costo_seguro_total);
    printf("Costo de combustible: %.2f\n", r.costo_combustible_total);
    printf("Costo de mantenimiento: %.2f\n", r.costo_mantenimiento_total);
    printf("Costo de vehiculo (depreciacion): %.2f\n", r.costo_vehiculo_total);
    printf("--------------------------------------\n");
    printf("Costo por km: %.4f\n", r.costo_por_km);
    printf("Costo total del viaje: %.2f\n", r.costo_total);
}

//Menus

void menu_vehiculos(Vehiculo* lista, int* n_ptr) {
    int salir = 0;
    while (!salir) {
        printf("\n==== Gestion de vehiculo ====%\n");
        printf("1) Crear\n");
        printf("2) Borrar\n");
        printf("3) Modificar\n");
        printf("4) Listar\n");
        printf("0) Volver\n");
        int op = leer_entero("Opcion: ");
        switch (op) {
            case 1: crear_vehiculo(lista, n_ptr); break;
            case 2: borrar_vehiculo(lista, n_ptr); break;
            case 3: modificar_vehiculo(lista, *n_ptr); break;
            case 4: listar_vehiculos(lista, *n_ptr); break;
            case 0: salir = 1; break;
            default: printf("Opcion invalida.\n");
        }
    }
}

void menu_datos_generales(DatosGenerales* dg) {
    int salir = 0;
    while (!salir) {
        printf("\n==== Gestion de datos generales ====%\n");
        printf("1) Mostrar\n");
        printf("2) Editar costos de combustible\n");
        printf("0) Volver\n");
        int op = leer_entero("Opcion: ");
        switch (op) {
            case 1: mostrar_datos_generales(dg); break;
            case 2: editar_datos_generales(dg); break;
            case 0: salir = 1; break;
            default: printf("Opcion invalida.\n");
        }
    }
}

int main(void) {
    Vehiculo vehiculos[MAX_VEHICULOS];
    int n_vehiculos = 0;

    DatosGenerales datos = { 0.0, 0.0 }; // inicializar costos de combustible

    int salir = 0;
    while (!salir) {
        printf("\n==============================\n");
        printf(" Programa de gestion de gastos \n");
        printf("==============================\n");
        printf("1) Gestion de vehiculo (Crear, Borrar, Modificar, Listar)\n");
        printf("2) Gestion de datos generales (costos de combustible)\n");
        printf("3) Calculo costo de viaje\n");
        printf("0) Salir\n");
        int op = leer_entero("Opcion: ");
        switch (op) {
            case 1: menu_vehiculos(vehiculos, &n_vehiculos); break;
            case 2: menu_datos_generales(&datos); break;
            case 3: flujo_calculo_viaje(vehiculos, n_vehiculos, &datos); break;
            case 0: salir = 1; break;
            default: printf("Opcion invalida.\n");
        }
    }

    printf("Fin del programa.\n");
    return 0;
}
