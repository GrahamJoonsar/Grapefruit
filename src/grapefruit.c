#include "grapefruit.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

Image * new_image(size_t width, size_t height){
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

void save_image(Image * img, const char * path){
    FILE * file = fopen(path, "w");
    fprintf(file, "P3 %d %d %d\n", img->width, img->height, 255);
    for (int i = 0; i < img->width*img->height; i++){
        fprintf(file, "%d %d %d  ", 
            GET_RED(img->pixels[i]),
            GET_GREEN(img->pixels[i]),
            GET_BLUE(img->pixels[i])
        );
        if (i%img->width == img->width-1) fprintf(file, "\n");
    }
    fclose(file);
}