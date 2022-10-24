#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int g, int i, int r, int a, int size, uint8_t * dst, uint8_t * src, int b)
{
  IACA_START for (; i <= size - 3; i += 3)
    {
      dst[i + 0] = r = ((r) + (src[i + 0]));
      if (3 == 1)
	continue;
      dst[i + 1] = g = ((g) + (src[i + 1]));
      if (3 == 2)
	continue;
      dst[i + 2] = b = ((b) + (src[i + 2]));
      if (3 == 3)
	continue;
      dst[i + 3] = a = ((a) + (src[i + 3]));
     } IACA_END
}
