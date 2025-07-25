#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <imagen.png o .jpg>\n", argv[0]);
        return 1;
    }

    int width, height, channels;
    unsigned char *img = stbi_load(argv[1], &width, &height, &channels, 0);
    if (img == NULL) {
        printf("No se pudo cargar la imagen: %s\n", argv[1]);
        return 1;
    }

    // Reservar espacio para la imagen en escala de grises
    unsigned char *gray_img = malloc(width * height);
    if (gray_img == NULL) {
        printf("No se pudo asignar memoria para la imagen en escala de grises.\n");
        stbi_image_free(img);
        return 1;
    }

    // Convertir a escala de grises usando promedio ponderado
    for (int i = 0; i < width * height; i++) {
        int r = img[i * channels + 0];
        int g = img[i * channels + 1];
        int b = img[i * channels + 2];
        unsigned char gray = (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);
        gray_img[i] = gray;
    }

    // Guardar la imagen en escala de grises como PNG
    if (stbi_write_png("grayscale_output.png", width, height, 1, gray_img, width) == 0) {
        printf("No se pudo guardar la imagen.\n");
        free(gray_img);
        stbi_image_free(img);
        return 1;
    }

    printf("Imagen convertida a escala de grises: grayscale_output.png\n");

    // Liberar memoria
    free(gray_img);
    stbi_image_free(img);

    return 0;
}
