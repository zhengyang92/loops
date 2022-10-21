#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int y, int fact, ptrdiff_t stride, int x, int idx, const uint16_t * ref,
    uint16_t * src, int size)
{
  for (x = 0; x < size; x++)
     { IACA_START
      src[(x) + stride * (y)] =
	((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
     } IACA_END
}
