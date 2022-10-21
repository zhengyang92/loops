#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, int num_pixels, uint8_t * dst, int i)
{
  for (i = 0; i < num_pixels; i++)
     { IACA_START
      unsigned rgb = ((const uint16_t *) src)[i];
      unsigned br = rgb & 0x7C1F;
      ((uint16_t *) dst)[i] = (br >> 10) | (rgb & 0x3E0) | (br << 10);
} IACA_END }
