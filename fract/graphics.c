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
