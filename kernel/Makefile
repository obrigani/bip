.SUFFIXES =

override OUTPUT := kernel

TOOLCHAIN_PREFIX := i686-elf-

CC = $(TOOLCHAIN_PREFIX)gcc
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

CFLAGS += -Iinclude \

LDFLAGS = -T linker.lds \
		  -ffreestanding \
		  -O2 \
		  -nostdlib \
		  -lgcc
    	 
AS = $(TOOLCHAIN_PREFIX)as

override SRCFILES := $(shell find -L src -type f 2>/dev/null | LC_ALL=C sort)
override CFILES := $(filter %.c,$(SRCFILES))
override ASFILES := $(filter %.asm,$(SRCFILES))
override OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(ASFILES:.asm=.asm.o))

bin/$(OUTPUT): Makefile linker.lds $(OBJ)
	mkdir -p "$(dir $@)"
	$(CC) $(LDFLAGS) $(OBJ) -o $@

obj/%.c.o: %.c Makefile
	mkdir -p "$(dir $@)"
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.asm.o: %.asm Makefile
	mkdir -p "$(dir $@)"
	$(AS) -c $< -o $@

.PHONY: clean
clean:
	rm -fr obj bin

.PHONY: distclean
distclean:
	rm -fr .deps-obtained compile_commands.json
