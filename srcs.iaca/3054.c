#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (unsigned int j, int16_t * dst, ptrdiff_t stride, int width,
    unsigned int k, int rlen)
{
  for (k = 0; k < rlen; k++)
     { IACA_START
      dst[j++] = 0;
      if (j == width)
	{
	  j = 0;
	  dst += stride;
	}
     } IACA_END
}
