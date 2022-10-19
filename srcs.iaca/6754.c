#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int g, int i, int r, int a, int size, uint8_t * dst, uint8_t * src, int b)
{
  for (; i < size; i += 4)
    {
      dst[i + 0] = r = r + src[i + 0];
      if (4 == 1)
	continue;
      dst[i + 1] = g = g + src[i + 1];
      if (4 == 2)
	continue;
      dst[i + 2] = b = b + src[i + 2];
      if (4 == 3)
	continue;
      dst[i + 3] = a = a + src[i + 3];
    }
}
