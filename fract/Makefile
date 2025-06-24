CC = x86_64-w64-mingw32-gcc
CFLAGS = -I. -Wl,-dll -shared -Wl,--subsystem,10 -nostdlib -ffreestanding -e efi_main -o BOOTX64.EFI
CFILES = main.c

fract.img: BOOTX64.EFI
	dd if=/dev/zero of=fract.img bs=1k count=1440
	mformat -i fract.img -f 1440 ::
	mmd -i fract.img ::/EFI
	mmd -i fract.img ::/EFI/BOOT
	mcopy -i fract.img BOOTX64.EFI ::/EFI/BOOT

BOOTX64.EFI:
	 $(CC) $(CFLAGS) $(CFILES)

.PHONY: clean
clean:
	rm BOOTX64.EFI fract.img
