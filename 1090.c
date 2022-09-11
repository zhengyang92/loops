#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int t0, uint8_t * dst1, const int slicew_end,
    const int slicew_start, int x, const uint8_t * src, const int t1,
    uint8_t * dst0, const int bg, const int step)
{
  for (x = slicew_start * step; x < slicew_end * step; x++)
    {
      if (src[x] != bg)
	{
	  dst0[x] = t0;
	  dst1[x] = t1;
	}
    }
}
