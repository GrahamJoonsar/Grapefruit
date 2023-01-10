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

void save_image(Image * img, const char * path){
    FILE * file = fopen(path, "w");
    fprintf(file, "P3 %d %d %d\n", img->width, img->height, 255);
    for (int i = 0; i < img->width*img->height; i++){
        if (i%img->width == 0) fprintf(file, "\n");
        fprintf(file, "%d %d %d  ", 
            GET_RED(img->pixels[i]),
            GET_GREEN(img->pixels[i]),
            GET_BLUE(img->pixels[i])
        );
    }
    fclose(file);
}