#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int map, int i, int lo, int hi, uint8_t * out, int stride)
{
  for (i = 0; i < 4; i++)
    {
      if (map & 1)
	out[0] = hi;
      else
	out[0] = lo;
      if (map & 2)
	out[1] = hi;
      else
	out[1] = lo;
      if (map & 4)
	out[2] = hi;
      else
	out[2] = lo;
      if (map & 8)
	out[3] = hi;
      else
	out[3] = lo;
      map >>= 4;
      out += stride;
    }
}
