#include "image.h"

#define GF_UNSAFE
#include "grapefruit.h"

int main(void){
    Image * img = new_image(10, 10);

    gf_clear(img, RGB(0, 0, 0));
    gf_rect(img, 1, 1, 8, 8, RGB(255, 255, 255));
    save_image(img, "img.ppm");

    free_image(img);
}