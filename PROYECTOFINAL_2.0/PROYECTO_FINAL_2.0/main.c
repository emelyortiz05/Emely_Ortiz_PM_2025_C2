#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VEHICULOS 100

typedef enum { COMBUSTIBLE_GASOLINA=1, COMBUSTIBLE_GASOIL=2 } TipoCombustible;

typedef struct {
    char placa[16]; char marca[32]; char modelo[32];
    TipoCombustible tipo_combustible;
    double km_x_galon_carretera, km_x_galon_ciudad;
    double costo_gomas, km_gomas, costo_seguro_12m;
    double costo_mantenimiento, km_mantenimiento, costo_vehiculo;
    double vida_util_km, km_por_agno_promedio;
} Vehiculo;

typedef struct { double costo_gasolina_por_galon, costo_gasoil_por_galon; } DatosGenerales;

typedef struct { double costo_gomas_total, costo_seguro_total, costo_combustible_total, costo_mantenimiento_total, costo_vehiculo_total, costo_total, costo_por_km; } ResultadoViaje;

void limpiar_buffer() { int c; while((c=getchar())!='\n' && c!=EOF){} }
void leer_cadena(const char* p, char* d, size_t t){ printf("%s", p); if(fgets(d,(int)t,stdin)==NULL){ d[0]='\0'; return;} size_t n=strlen(d); if(n>0 && d[n-1]=='\n') d[n-1]='\0'; }
int leer_entero(const char* p){ int v,ok=0; do{ printf("%s",p); if(scanf("%d",&v)==1) ok=1; else printf("Entrada invalida.\n"); limpiar_buffer(); }while(!ok); return v;}
double leer_double(const char* p){ double v; int ok=0; do{ printf("%s",p); if(scanf("%lf",&v)==1) ok=1; else printf("Entrada invalida.\n"); limpiar_buffer(); }while(!ok); return v;}

void guardar_datos(const Vehiculo* l,int n,const DatosGenerales* dg){
    FILE* f=fopen("vehiculos.dat","wb"); if(f){ fwrite(&n,sizeof(int),1,f); fwrite(l,sizeof(Vehiculo),n,f); fclose(f);}
    f=fopen("datos_generales.dat","wb"); if(f){ fwrite(dg,sizeof(DatosGenerales),1,f); fclose(f);}
}

void cargar_datos(Vehiculo* l,int* n,DatosGenerales* dg){
    FILE* f=fopen("vehiculos.dat","rb");
    if(f){ fread(n,sizeof(int),1,f); fread(l,sizeof(Vehiculo),*n,f); fclose(f);}
    else{ *n=3; Vehiculo ej[3]={{"A1234","Toyota","Corolla",COMBUSTIBLE_GASOLINA,40,30,28000,40000,35000,5000,10000,1000000,250000,20000},
                               {"B5678","Hyundai","Tucson",COMBUSTIBLE_GASOIL,35,28,30000,45000,40000,6000,12000,1500000,300000,22000},
                               {"C9101","Kia","Rio",COMBUSTIBLE_GASOLINA,38,32,27000,38000,30000,4800,10000,950000,230000,18000}};
          for(int i=0;i<*n;i++) l[i]=ej[i]; }
    f=fopen("datos_generales.dat","rb");
    if(f){ fread(dg,sizeof(DatosGenerales),1,f); fclose(f);}
    else{ dg->costo_gasolina_por_galon=293.10; dg->costo_gasoil_por_galon=230.20; }
}

int buscar_vehiculo_por_placa(Vehiculo* l,int n,const char* placa){ for(int i=0;i<n;i++) if(strcmp(l[i].placa,placa)==0) return i; return -1; }

void listar_vehiculos(Vehiculo* l,int n){
    if(n==0){ printf("No hay vehiculos.\n"); return;}
    printf("\n==== Vehiculos registrados ====\n");
    for(int i=0;i<n;i++){
        Vehiculo *v=&l[i];
        printf("%2d) %s | %s %s | %s | Carretera: %.2f | Ciudad: %.2f\n", i+1,v->placa,v->marca,v->modelo, v->tipo_combustible==COMBUSTIBLE_GASOLINA?"Gasolina":"Gasoil",v->km_x_galon_carretera,v->km_x_galon_ciudad);
    }
}

void crear_vehiculo(Vehiculo* l,int* n_ptr,DatosGenerales* dg){
    int n=*n_ptr; if(n>=MAX_VEHICULOS){ printf("Capacidad maxima.\n"); return;}
    Vehiculo v; leer_cadena("Placa: ",v.placa,sizeof(v.placa)); if(buscar_vehiculo_por_placa(l,n,v.placa)!=-1){ printf("Ya existe.\n"); return;}
    leer_cadena("Marca: ",v.marca,sizeof(v.marca)); leer_cadena("Modelo: ",v.modelo,sizeof(v.modelo));
    int tc; do{ tc=leer_entero("Tipo (1=Gasolina,2=Gasoil): "); }while(tc!=1 && tc!=2); v.tipo_combustible=tc==1?COMBUSTIBLE_GASOLINA:COMBUSTIBLE_GASOIL;
    v.km_x_galon_carretera=leer_double("Km/gal carretera: "); v.km_x_galon_ciudad=leer_double("Km/gal ciudad: ");
    v.costo_gomas=leer_double("Costo gomas: "); v.km_gomas=leer_double("Km gomas: "); v.costo_seguro_12m=leer_double("Costo seguro 12m: ");
    v.costo_mantenimiento=leer_double("Costo mantenimiento: "); v.km_mantenimiento=leer_double("Km mantenimiento: ");
    v.costo_vehiculo=leer_double("Costo vehiculo: "); v.vida_util_km=leer_double("Vida util km: "); v.km_por_agno_promedio=leer_double("Km/año promedio: ");
    l[n]=v; *n_ptr=n+1; guardar_datos(l,*n_ptr,dg);
}

void borrar_vehiculo(Vehiculo* l,int* n_ptr,DatosGenerales* dg){
    if(*n_ptr==0){ printf("No hay vehiculos.\n"); return;}
    char placa[16]; leer_cadena("Placa a borrar: ",placa,sizeof(placa));
    int idx=buscar_vehiculo_por_placa(l,*n_ptr,placa); if(idx==-1){ printf("No existe.\n"); return;}
    for(int i=idx;i<*n_ptr-1;i++) l[i]=l[i+1]; (*n_ptr)--; guardar_datos(l,*n_ptr,dg);
}

void mostrar_datos_generales(const DatosGenerales* dg){ printf("\n=== Costos Combustible ===\nGasolina: %.2f\nGasoil: %.2f\n",dg->costo_gasolina_por_galon,dg->costo_gasoil_por_galon); }

void editar_datos_generales(DatosGenerales* dg,Vehiculo* l,int n){ dg->costo_gasolina_por_galon=leer_double("Nuevo costo gasolina: "); dg->costo_gasoil_por_galon=leer_double("Nuevo costo gasoil: "); guardar_datos(l,n,dg); }

ResultadoViaje calcular_viaje(const Vehiculo* v,const DatosGenerales* dg,double km,double pct_ciudad){
    ResultadoViaje r={0}; if(km<=0) return r; if(pct_ciudad<0) pct_ciudad=0; if(pct_ciudad>100) pct_ciudad=100;
    double km_ciudad=km*(pct_ciudad/100.0),km_carre=km-km_ciudad;
    double gal_ciudad=v->km_x_galon_ciudad>0? km_ciudad/v->km_x_galon_ciudad:0;
    double gal_carre=v->km_x_galon_carretera>0? km_carre/v->km_x_galon_carretera:0;
    double gal_total=gal_ciudad+gal_carre;
    double precio_galon=v->tipo_combustible==COMBUSTIBLE_GASOLINA?dg->costo_gasolina_por_galon:dg->costo_gasoil_por_galon;
    r.costo_combustible_total=gal_total*precio_galon;
    r.costo_gomas_total=v->km_gomas>0?(v->costo_gomas/v->km_gomas)*km:0;
    r.costo_seguro_total=v->km_por_agno_promedio>0?(v->costo_seguro_12m/v->km_por_agno_promedio)*km:0;
    r.costo_mantenimiento_total=v->km_mantenimiento>0?(v->costo_mantenimiento/v->km_mantenimiento)*km:0;
    r.costo_vehiculo_total=v->vida_util_km>0?(v->costo_vehiculo/v->vida_util_km)*km:0;
    r.costo_total=r.costo_gomas_total+r.costo_seguro_total+r.costo_combustible_total+r.costo_mantenimiento_total+r.costo_vehiculo_total;
    r.costo_por_km=r.costo_total/km; return r;
}

void flujo_calculo_viaje(Vehiculo* l,int n,const DatosGenerales* dg){
    if(n==0){ printf("No hay vehiculos.\n"); return;}
    listar_vehiculos(l,n);
    int opcion=leer_entero("Seleccione vehiculo: "); if(opcion<1 || opcion>n){ printf("Invalido.\n"); return;}
    Vehiculo *v=&l[opcion-1];
    double km=leer_double("Kilometros: "); double pct=leer_double("Porcentaje ciudad (0-100): ");
    ResultadoViaje r=calcular_viaje(v,dg,km,pct);
    printf("\n===== Resultado =====\nCosto total: %.2f | Costo/km: %.4f\n",r.costo_total,r.costo_por_km);
}

void menu_vehiculos(Vehiculo* l,int* n_ptr,DatosGenerales* dg){
    int salir=0;
    while(!salir){
        printf("\n==== Gestion Vehiculos ====\n1) Crear\n2) Borrar\n3) Listar\n0) Volver\n");
        int op=leer_entero("Opcion: ");
        switch(op){ case 1: crear_vehiculo(l,n_ptr,dg); break; case 2: borrar_vehiculo(l,n_ptr,dg); break; case 3: listar_vehiculos(l,*n_ptr); break; case 0: salir=1; break;}
    }
}

void menu_datos_generales(DatosGenerales* dg,Vehiculo* l,int n){
    int salir=0;
    while(!salir){
        printf("\n==== Datos Generales ====\n1) Mostrar\n2) Editar\n0) Volver\n");
        int op=leer_entero("Opcion: ");
        switch(op){ case 1: mostrar_datos_generales(dg); break; case 2: editar_datos_generales(dg,l,n); break; case 0: salir=1; break;}
    }
}

int main(void){
    Vehiculo vehiculos[MAX_VEHICULOS]; int n_vehiculos=0; DatosGenerales datos;
    cargar_datos(vehiculos,&n_vehiculos,&datos);

    int salir=0;
    while(!salir){
        printf("\n==============================\n  Programa de Gestion de Gastos  \n==============================\n1) Gestion Vehiculos\n2) Datos Generales\n3) Calculo Viaje\n0) Salir\n");
        int op=leer_entero("Opcion: ");
        switch(op){ case 1: menu_vehiculos(vehiculos,&n_vehiculos,&datos); break; case 2: menu_datos_generales(&datos,vehiculos,n_vehiculos); break; case 3: flujo_calculo_viaje(vehiculos,n_vehiculos,&datos); break; case 0: salir=1; break;}
    }
    guardar_datos(vehiculos,n_vehiculos,&datos); return 0;
}
