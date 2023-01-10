#include "grapefruit.h"

#include <stdio.h>

int main(void){
    Image * img = new_image(255, 255);
    for (int x = 0; x < img->width; x++){
    for (int y = 0; y < img->height; y++){
        img->pixels[y*img->width + x] = RGB(0, 0, 255);
    }}
    save_image(img, "img.ppm");

    free_image(img);
}