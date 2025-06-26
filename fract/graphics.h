#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <system.h>

extern EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
extern EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* gop_info;
extern UINTN gop_info_size;
extern UINTN screen_width;
extern UINTN screen_height;

struct point {
  uint32_t x;
  uint32_t y;
};

EFI_STATUS init_graphics();

uint32_t get_pixel(struct point p);
int set_pixel(struct point p, uint32_t val);

EFI_STATUS fill_framebuffer(uint32_t val);

#endif
