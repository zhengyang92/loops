#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint8_t * v, int i, const uint16_t * rgb, int width, int YUV_HALF,
    uint8_t * u)
{
  for (i = 0; i < width; i += 1, rgb += 4)
    {
      const int r = rgb[0], g = rgb[1], b = rgb[2];
      u[i] = VP8RGBToU (r, g, b, YUV_HALF << 2);
      v[i] = VP8RGBToV (r, g, b, YUV_HALF << 2);
}}
