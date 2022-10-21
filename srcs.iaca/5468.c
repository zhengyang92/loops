#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int num_pixels, int i, const uint8_t * src, uint8_t * dst)
{
  for (i = 0; i < num_pixels; i++)
     { IACA_START
      unsigned rgb = ((const uint16_t *) src)[i];
      unsigned br = rgb & 0x7C1F;
      ((uint16_t *) dst)[i] = (br >> 10) | (rgb & 0x3E0) | (br << 10);
} IACA_END }
