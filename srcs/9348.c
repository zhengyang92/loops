#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * ref, int fact, int y, ptrdiff_t stride, int x, int idx,
    int size, uint8_t * src)
{
  for (x = 0; x < size; x++)
    {
      src[(x) + stride * (y)] =
	((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
    }
}
