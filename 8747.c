#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (const uint8_t * ref, int fact, int y, ptrdiff_t stride, int x, int idx,
    int size, uint8_t * src)
{
  for (y = 0; y < size; y++)
    {
      src[(x) + stride * (y)] =
	((32 - fact) * ref[y + idx + 1] + fact * ref[y + idx + 2] + 16) >> 5;
    }
}
