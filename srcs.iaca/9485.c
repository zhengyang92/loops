#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (unsigned int j, int16_t * dst, ptrdiff_t stride, int width,
    unsigned int rlen, unsigned int k)
{
  for (k = 0; k < rlen; k++)
    {
      dst[j++] = 0;
      if (j == width)
	{
	  j = 0;
	  dst += stride;
	}
    }
}
