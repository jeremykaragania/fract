#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <system.h>

extern EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
extern EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* gop_info;
extern UINTN gop_info_size;

EFI_STATUS init_graphics();

uint32_t get_pixel(uint32_t x, uint32_t y);
int set_pixel(uint32_t x, uint32_t y, uint32_t val);

#endif
