#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (const uint8_t * ref, int y, int fact, ptrdiff_t stride, int x, int idx,
    int size, uint8_t * src)
{
  for (x = 0; x < size; x++)
    {
      src[(x) + stride * (y)] =
	((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
    }
}
