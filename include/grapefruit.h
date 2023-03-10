#ifndef GRAPEFRUIT_H
#define GRAPEFRUIT_H

#include "image.h"

void gf_fill_circle(Image * img, int x, int y, int r, uint32_t color);
void gf_clear(Image * img, uint32_t color);
void gf_fill_rect(Image * img, int x, int y, int w, int h, uint32_t color);
void gf_rect(Image * img, int x, int y, int w, int h, uint32_t color);

#endif