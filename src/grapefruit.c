#include "grapefruit.h"

void gf_fill_circle(Image * img, int x, int y, int r, uint32_t color){
    #ifndef GF_UNSAFE
        if (img == NULL) return;
    #endif
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
    #ifndef GF_UNSAFE
        if (img == NULL) return;
    #endif
    for (int i = 0; i < img->width * img->height; i++){
        img->pixels[i] = color;
    }
}

void gf_fill_rect(Image * img, int x, int y, int w, int h, uint32_t color){
    #ifndef GF_UNSAFE
        if (img == NULL) return;
    #endif
    int min_x = x < 0 ? 0 : x;
    int max_x = x + w >= img->width ? img->width-1 : x + w;
    int min_y = y < 0 ? 0 : y;
    int max_y = y + h >= img->height ? img->height-1 : y + h;
    
    for (int i = min_x; i < max_x; i++){
    for (int j = min_y; j < max_y; j++){
        img->pixels[j*img->width + i] = color;
    }}
}

void gf_rect(Image * img, int x, int y, int w, int h, uint32_t color){
    #ifndef GF_UNSAFE
        if (img == NULL) return;
    #endif
    int min_x = x < 0 ? 0 : x;
    int max_x = x + w >= img->width ? img->width-1 : x + w;
    int min_y = y < 0 ? 0 : y;
    int max_y = y + h >= img->height ? img->height-1 : y + h;

    for (int i = min_x; i < max_x; i++){
        img->pixels[min_y*img->width + i] = color;
        img->pixels[(max_y-1)*img->width + i] = color;
    }

    for (int i = min_y + 1; i < max_y - 1; i++){
        img->pixels[i*img->width + min_x] = color;
        img->pixels[i*img->width + (max_x-1)] = color;
    }
}