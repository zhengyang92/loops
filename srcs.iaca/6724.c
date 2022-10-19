#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t mask, int i, int width, const uint8_t * src, uint8_t * dst)
{
  for (i = 0; i < 4; i++)
    {
      if (mask & (1 << 7 - i))
	dst[i] = src[i];
      if (mask & (1 << 3 - i))
	dst[width + i] = src[width + i];
    }
}
