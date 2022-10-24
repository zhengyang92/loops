#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * tmp, const int w2, int x, int32_t * b)
{
  IACA_START for (x = 0; x < w2; x++)
    {
      b[2 * x] = ((int) (tmp[x] + 1U)) >> 1;
      b[2 * x + 1] =
	((int)
	 ((int)
	  (((unsigned) (b[x + w2]) +
	    ((int)
	     (9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] +
	      8) >> 4))) + 1U)) >> 1;
}IACA_END}
