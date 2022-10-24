#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int y, int fact, ptrdiff_t stride, int x, int idx, uint16_t * src,
    const uint16_t * ref, int size)
{
  IACA_START for (x = 0; x < size; x++)
    {
      src[(x) + stride * (y)] =
	((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
     } IACA_END
}
