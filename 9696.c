#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int width, uint8_t * dst, const uint8_t * src, int i)
{
  for (i = 0; i < width; i++)
    {
      int b = src[i * 3 + 0];
      int g = src[i * 3 + 1];
      int r = src[i * 3 + 2];
      dst[i] =
	((((int) (0.299 * 219 / 255 * (1 << 15) + 0.5)) * r +
	  ((int) (0.587 * 219 / 255 * (1 << 15) + 0.5)) * g +
	  ((int) (0.114 * 219 / 255 * (1 << 15) + 0.5)) * b +
	  (33 << (15 - 1))) >> 15);
}}
