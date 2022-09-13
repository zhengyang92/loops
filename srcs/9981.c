#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int i, int width, int YUV_HALF, const uint32_t * argb, uint8_t * y)
{
  for (i = 0; i < width; ++i)
    {
      const uint32_t p = argb[i];
      y[i] =
	VP8RGBToY ((p >> 16) & 0xff, (p >> 8) & 0xff, (p >> 0) & 0xff,
		   YUV_HALF);
}}
