#include <efi/efi.h>
#include <efi/efilib.h>
#include <mandelbrot.h>

EFI_STATUS efi_main(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable) {
  EFI_STATUS status;
  EFI_INPUT_KEY key;

  system_table = SystemTable;

  status = init_graphics();

  if (EFI_ERROR(status)) {
    return status;
  }

  status = system_table->ConIn->Reset(system_table->ConIn, FALSE);
  if (EFI_ERROR(status)) {
    return status;
  }

  draw_mandelbrot();

  while ((status = system_table->ConIn->ReadKeyStroke(system_table->ConIn, &key)) == EFI_NOT_READY) ;

  return EFI_SUCCESS;
}
