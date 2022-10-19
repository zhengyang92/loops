#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int x, int width, const uint8_t * src, uint8_t * dst,
    const uint32_t * const color_map)
{
  for (x = 0; x < width; ++x)
    {
      *dst++ = VP8GetAlphaValue (color_map[VP8GetAlphaIndex (*src++)]);
    }
}
