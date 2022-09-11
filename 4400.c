#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int offset, const uint16_t * msrc, int x, int half, int shift,
    const uint16_t * asrc, uint16_t * dst)
{
  for (x = 0; x < w; x++)
    {
      dst[x] =
	((((msrc[x] - offset) * (int64_t) (((asrc[x] >> 1) & 1) + asrc[x])) +
	  half) >> shift) + offset;
    }
}
