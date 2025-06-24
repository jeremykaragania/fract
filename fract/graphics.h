#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <system.h>

extern EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
extern EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* gop_info;
extern UINTN gop_info_size;

EFI_STATUS init_graphics();

#endif
