#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int num_pixels, uint8_t * dst, const uint8_t * src, int i)
{
  for (i = 0; i < num_pixels; i++)
     { IACA_START
      register uint8_t rgb = src[i];
      unsigned r = (rgb & 0x07);
      unsigned g = (rgb & 0x38) >> 3;
      unsigned b = (rgb & 0xC0) >> 6;
      dst[i] = ((b << 1) & 0x07) | ((g & 0x07) << 3) | ((r & 0x03) << 6);
} IACA_END }
