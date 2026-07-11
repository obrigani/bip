.SUFFIXES:

QEMUFLAGS := -m 2G -vga virtio

override IMAGE_NAME := bip

HOST_CC := cc
HOST_CFLAGS := -g -O2 -pipe

.PHONY: run
run: $(IMAGE_NAME).iso
	qemu-system-i386 \
	-cdrom $(IMAGE_NAME).iso \
	$(QEMUFLAGS)

.PHONY: run-grub
run-grub: $(IMAGE_NAME)-grub.iso
	qemu-system-i386 \
	-cdrom $(IMAGE_NAME)-grub.iso \
	$(QEMUFLAGS)

.PHONY: all
all: $(IMAGE_NAME).iso

kernel/.deps-obtained:
	./kernel/get-deps

limine-binary:
	curl -L https://github.com/Limine-Bootloader/Limine/releases/latest/download/limine-binary.tar.gz | gunzip | tar -xf -
	
.PHONY: kernel
kernel: kernel/.deps-obtained
	$(MAKE) -C kernel

$(IMAGE_NAME).iso: kernel limine-binary
	make -C limine-binary
	mkdir -p isodir

	mkdir -p isodir/boot
	cp -v kernel/bin/kernel isodir/boot/
	mkdir -p isodir/boot/limine
	cp -v limine.conf limine-binary/limine-bios.sys limine-binary/limine-bios-cd.bin \
	      limine-binary/limine-uefi-cd.bin isodir/boot/limine/

	mkdir -p isodir/EFI/BOOT
	cp -v limine-binary/BOOTX64.EFI isodir/EFI/BOOT/
	cp -v limine-binary/BOOTIA32.EFI isodir/EFI/BOOT/

	xorriso -as mkisofs -R -r -J -b boot/limine/limine-bios-cd.bin \
	        -no-emul-boot -boot-load-size 4 -boot-info-table -hfsplus \
	        -apm-block-size 2048 --efi-boot boot/limine/limine-uefi-cd.bin \
	        -efi-boot-part --efi-boot-image --protective-msdos-label \
	        isodir -o $(IMAGE_NAME).iso

	./limine-binary/limine bios-install $(IMAGE_NAME).iso

	rm -fr isodir

$(IMAGE_NAME)-grub.iso: kernel
	mkdir -p isodir/boot/grub
	cp kernel/bin/kernel isodir/boot/
	cp grub.cfg isodir/boot/grub/
	grub-mkrescue -o $(IMAGE_NAME)-grub.iso isodir
	rm -fr isodir

.PHONY: clean
clean:
	make -C kernel clean
	rm -fr $(IMAGE_NAME).iso \
		   $(IMAGE_NAME)-grub.iso \
		   isodir 

.PHONY: distclean
distclean:
	make -C kernel distclean
	rm -fr limine-binary
