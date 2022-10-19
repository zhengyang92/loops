#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int height, int y, int zw, const uint8_t * xf0, float progress,
    const uint8_t * xf1, const int width, int zh, uint8_t * dst, const int bg)
{
  for (int x = 0; x < width; x++)
    {
      int dist =
	((x - width / 2) >= 0 ? (x - width / 2) : (-(x - width / 2))) < zw
	&& ((y - height / 2) >= 0 ? (y - height / 2) : (-(y - height / 2))) <
	zh;
      int val = progress < 0.5f ? xf1[x] : xf0[x];
      dst[x] = !dist ? bg : val;
}}
