#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int y, const uint8_t * ref, int fact, ptrdiff_t stride, int x, int idx,
    int size, uint8_t * src)
{
  for (x = 0; x < size; x += 4)
    {
      src[(x) + stride * (y)] =
	((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
      src[(x + 1) + stride * (y)] =
	((32 - fact) * ref[x + 1 + idx + 1] + fact * ref[x + 1 + idx + 2] +
	 16) >> 5;
      src[(x + 2) + stride * (y)] =
	((32 - fact) * ref[x + 2 + idx + 1] + fact * ref[x + 2 + idx + 2] +
	 16) >> 5;
      src[(x + 3) + stride * (y)] =
	((32 - fact) * ref[x + 3 + idx + 1] + fact * ref[x + 3 + idx + 2] +
	 16) >> 5;
    }
}
