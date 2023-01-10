#include "grapefruit.h"

void gf_fill_circle(Image * img, int x, int y, int r, uint32_t color){
    int min_x = x - r < 0 ? 0 : x - r;
    int max_x = x + r >= img->width ? img->width-1 : x + r;
    int min_y = y - r < 0 ? 0 : y - r;
    int max_y = y + r >= img->height ? img->height-1 : y + r;

    int r_2 = r*r;

    for (int sx = min_x; sx <= max_x; sx++){
    for (int sy = min_y; sy <= max_y; sy++){
        if ((sx-x)*(sx-x) + (sy-y)*(sy-y) <= r_2){
            img->pixels[sy*img->width + sx] = color;
        }
    }}
}

void gf_clear(Image * img, uint32_t color){
    for (int i = 0; i < img->width * img->height; i++){
        img->pixels[i] = color;
    }
}