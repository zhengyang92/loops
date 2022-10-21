#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int num_pixels, uint8_t * dst, const uint8_t * src, int i)
{
  for (i = 0; i < num_pixels; i++)
     { IACA_START
      unsigned rgb = ((const uint16_t *) src)[i];
      ((uint16_t *) dst)[i] =
	(rgb >> 11) | ((rgb & 0x7C0) >> 1) | ((rgb & 0x1F) << 10);
} IACA_END }
