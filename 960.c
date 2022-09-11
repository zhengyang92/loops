#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, const uint16_t * msrc, int x, int half, int shift,
    const uint16_t * asrc, uint16_t * dst)
{
  for (x = 0; x < w; x++)
    {
      dst[x] =
	((((msrc[x] - half) * (int64_t) (((asrc[x] >> 1) & 1) +
					 asrc[x]))) >> shift) + half;
    }
}
