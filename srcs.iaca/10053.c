#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef VP8Random;
typedef __uint16_t uint16_t;

int
fn (uint8_t * const dst_u, uint8_t * const dst_v, int i, const uint16_t * rgb,
    int width, VP8Random * const rg)
{
  for (i = 0; i < width; i += 1, rgb += 4)
    {
      const int r = rgb[0], g = rgb[1], b = rgb[2];
      dst_u[i] = RGBToU (r, g, b, rg);
      dst_v[i] = RGBToV (r, g, b, rg);
}}
