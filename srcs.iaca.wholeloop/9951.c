#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int x, int width, uint32_t * dst, const uint32_t * src,
    const uint32_t * const color_map)
{
  IACA_START for (x = 0; x < width; ++x)
    {
      *dst++ = VP8GetARGBValue (color_map[VP8GetARGBIndex (*src++)]);
     } IACA_END
}
