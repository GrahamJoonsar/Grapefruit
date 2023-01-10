#include "image.h"
#include "grapefruit.h"

int main(void){
    Image * img = new_image(255, 255);
    gf_clear(img, RGB(0, 0, 0));
    gf_fill_circle(img, img->width/2, img->height/2, 32, RGB(0, 255, 0));
    save_image(img, "img.ppm");

    free_image(img);
}