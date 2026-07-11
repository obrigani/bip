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

.PHONY: all
all: $(IMAGE_NAME).iso

kernel/.deps-obtained:
	./kernel/get-deps

.PHONY: kernel
kernel: kernel/.deps-obtained
	$(MAKE) -C kernel

$(IMAGE_NAME).iso: kernel
	mkdir -p isodir/boot/grub
	cp kernel/bin/kernel isodir/boot/
	cp grub.cfg isodir/boot/grub/
	grub-mkrescue -o bip.iso isodir
	rm -fr isodir

.PHONY: clean
clean:
	make -C kernel clean
	rm -fr $(IMAGE_NAME).iso 

.PHONY: distclean
distclean:
	make -C kernel distclean
