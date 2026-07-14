.SUFFIXES =

TOOLCHAIN_PREFIX := i686-elf-
CC = $(TOOLCHAIN_PREFIX)gcc
AR = $(TOOLCHAIN_PREFIX)ar
CFLAGS = -ffreestanding \
         -c \
         -std=gnu99 \
         -O2 \
         -Wall \
         -Wextra \
         -Wshadow \
         -pedantic \
         -Wconversion \
         -Wformat 

CFLAGS += -Iinclude 

LDFLAGS = -T linker.lds \
		  -ffreestanding \
		  -O2 \
		  -nostdlib \
		  -lgcc

BINARIES = libk.a

override SRCFILES := $(shell find -L string -type f 2>/dev/null | LC_ALL=C sort)
override CFILES := $(filter %.c,$(SRCFILES))
override ASFILES := $(filter %.asm,$(SRCFILES))
override OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(ASFILES:.asm=.asm.o))

libk.a: $(OBJ)
	$(AR) rcs $@ $(OBJ)

obj/%.c.o: %.c Makefile
	mkdir -p "$(dir $@)"
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -fr obj

.PHONY: distclean
distclean:
	@echo Distcleaned libk
