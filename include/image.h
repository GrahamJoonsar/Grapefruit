#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
#include <stddef.h>

struct Image {
    uint32_t * pixels;
    int width, height;
};
typedef struct Image Image;

Image * new_image(int width, int height);
void free_image(Image * img);
void save_image(Image * img, const char * path);

/* MACROS FOR COLORS */
// Pass in a uint64_t pixel, get the specific color value
#define GET_RED(pix)   (((pix)>>24)&255)
#define GET_GREEN(pix) (((pix)>>16)&255)
#define GET_BLUE(pix)  (((pix)>>8)&255)
#define GET_ALPHA(pix) ((pix)&255)

// Generate a color value, make sure 0 <= r, g, b, a <= 255
#define RGB(r, g, b)     (r)<<24 | (g)<<16 | (b)<<8 | (255)
#define RGBA(r, g, b, a) (r)<<24 | (g)<<16 | (b)<<8 | (a)

#endif
