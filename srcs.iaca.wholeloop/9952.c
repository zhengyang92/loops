#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const int bits_per_pixel, int x, const uint32_t bit_mask, const int width,
    uint32_t packed_pixels, uint32_t * dst, const uint32_t * src,
    const int count_mask, const uint32_t * const color_map)
{
  IACA_START for (x = 0; x < width; ++x)
    {
      if ((x & count_mask) == 0)
	packed_pixels = VP8GetARGBIndex (*src++);
      *dst++ = VP8GetARGBValue (color_map[packed_pixels & bit_mask]);
      packed_pixels >>= bits_per_pixel;
     } IACA_END
}
