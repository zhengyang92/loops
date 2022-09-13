#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t ** src, int width, uint8_t * dst, int i)
{
  for (i = 0; i < width; i++)
    {
      int g = src[0][i];
      int b = src[1][i];
      int r = src[2][i];
      dst[i] =
	((((int) (0.299 * 219 / 255 * (1 << 15) + 0.5)) * r +
	  ((int) (0.587 * 219 / 255 * (1 << 15) + 0.5)) * g +
	  ((int) (0.114 * 219 / 255 * (1 << 15) + 0.5)) * b +
	  (33 << (15 - 1))) >> 15);
}}
