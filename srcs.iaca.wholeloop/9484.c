#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long unsigned int size_t;
typedef long int ptrdiff_t;

int
fn (unsigned int j, int16_t * dst, size_t width, ptrdiff_t stride,
    unsigned int k, int rlen)
{
  IACA_START for (k = 0; k < rlen; k++)
    {
      dst[j++] = 0;
      if (j == width)
	{
	  j = 0;
	  dst += stride;
	}
     } IACA_END
}
