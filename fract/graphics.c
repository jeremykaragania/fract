#include <graphics.h>

EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* gop_info;
UINTN gop_info_size;

/*
 * init_graphics initializes the Graphics Output Protocol (GOP), initializing
 * global objects for graphics operations.
 */
EFI_STATUS init_graphics() {
  EFI_STATUS status;

  EFI_GUID gopGuid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;

  status = system_table->BootServices->LocateProtocol(&gopGuid, NULL, (void**)&gop);

  if (EFI_ERROR(status)) {
    return status;
  }

  status = gop->QueryMode(gop, gop->Mode->Mode, &gop_info_size, &gop_info);

  if (EFI_ERROR(status)) {
    return status;
  }

  return EFI_SUCCESS;
}

/*
 * get_pixel returns a copy of the pixel in the framebuffer from its x
 * coordinate, `x` and y coordinate, `y`.
 */
uint32_t get_pixel(uint32_t x, uint32_t y) {
  return ((uint32_t*)gop->Mode->FrameBufferBase)[y * gop_info->HorizontalResolution + x];
}

/*
 * set_pixel sets a pixel in the framebufffer to value `val` from its x
 * coordinate, `x` and y coordinate, `y`. If either coordinate is out of
 * bounds, then nothing is set. -1 is returned on failure and 0 on success.
 */
int set_pixel(uint32_t x, uint32_t y, uint32_t val) {
  if (x >= gop_info->HorizontalResolution || y >= gop_info->HorizontalResolution) {
    return -1;
  }

  ((uint32_t*)gop->Mode->FrameBufferBase)[y * gop_info->HorizontalResolution + x] = val;

  return 0;
}
