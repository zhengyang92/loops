#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const int bits_per_pixel, int x, const uint32_t bit_mask, const int width,
    uint32_t packed_pixels, const uint8_t * src, const int count_mask,
    uint8_t * dst, const uint32_t * const color_map)
{
  for (x = 0; x < width; ++x)
     { IACA_START
      if ((x & count_mask) == 0)
	packed_pixels = VP8GetAlphaIndex (*src++);
      *dst++ = VP8GetAlphaValue (color_map[packed_pixels & bit_mask]);
      packed_pixels >>= bits_per_pixel;
     } IACA_END
}
