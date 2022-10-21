#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int y, int fact, ptrdiff_t stride, int x, int idx, uint16_t * src,
    const uint16_t * ref, int size)
{
  for (y = 0; y < size; y++)
     { IACA_START
      src[(x) + stride * (y)] =
	((32 - fact) * ref[y + idx + 1] + fact * ref[y + idx + 2] + 16) >> 5;
     } IACA_END
}
