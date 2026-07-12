#pragma once

#include <stddef.h>
#include <stdint.h>

#define VGA_WIDTH   80
#define VGA_HEIGHT  25
#define VGA_ADDRESS 0xB8000

enum Vga_Color {
  VGA_COLOR_BLACK = 0,
  VGA_COLOR_BLUE,
  VGA_COLOR_GREEN,
  VGA_COLOR_CYAN,
  VGA_COLOR_RED,
  VGA_COLOR_MAGENTA,
  VGA_COLOR_BROWN,
  VGA_COLOR_LIGHT_GREY,
  VGA_COLOR_DARK_GREY,
  VGA_COLOR_LIGHT_BLUE,
  VGA_COLOR_LIGHT_GREEN,
  VGA_COLOR_LIGHT_CYAN,
  VGA_COLOR_LIGHT_RED,
  VGA_COLOR_LIGHT_MAGENTA,
  VGA_COLOR_LIGHT_BROWN,
  VGA_COLOR_WHITE
};

extern size_t term_row;
extern size_t term_col;
extern uint8_t term_color;
extern uint16_t* term_buffer;

static inline uint8_t vga_entry_color(enum Vga_Color fg, enum Vga_Color bg) \
{
  return (uint8_t)(fg | bg << 4);
}

void init_term(void);
void term_set_color(uint8_t color);
void term_write(const char* data, size_t size);
void term_print(const char* data);
