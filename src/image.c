#include "image.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

Image * new_image(int width, int height){
    Image * img = malloc(sizeof(Image));

    img->pixels = malloc(sizeof(uint32_t) * width * height);
    img->width = width;
    img->height = height;

    return img;
}

void free_image(Image * img){
    free(img->pixels);
    free(img);
}

int char_width(uint8_t n){
    if (0 <= n && n <= 9)    return 1;
    if (10 <= n && n <= 99)  return 2;
    if (10 <= n && n <= 999) return 3;
}

void save_image(Image * img, const char * path){
    FILE * file = fopen(path, "w");
    fprintf(file, "P3 %d %d %d\n", img->width, img->height, 255);
    for (int i = 0; i < img->width*img->height; i++){
        if (i%img->width == 0) fprintf(file, "\n");
        uint8_t r = GET_RED(img->pixels[i]);
        uint8_t g = GET_BLUE(img->pixels[i]);
        uint8_t b = GET_GREEN(img->pixels[i]);
        fprintf(file, "%d %d %d", r, g, b);
        for (int i = 0; i < 11-(char_width(r)+char_width(g)+char_width(b)); i++){
            fprintf(file, " ");
        }
    }
    fclose(file);
}