#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;
typedef long unsigned int size_t;

int
fn (int i, int16_t * srcy, uint16_t * dsty, size_t w, int depth)
{
  for (i = 0; i < w; i++)
    {
      if (srcy[i] <= 0)
	dsty[i] = 0;
      else if (srcy[i] > ((1 << depth) - 1))
	dsty[i] = 65535;
      else
	dsty[i] =
	  ((int64_t) srcy[i] * srcy[i] * 65535) / ((1 << depth) -
						   1) / ((1 << depth) - 1);
    }
}
