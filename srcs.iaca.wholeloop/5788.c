#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int blockstodecode, int i, int32_t * out)
{
  IACA_START for (i = 0; i < blockstodecode; i++)
    {
      if (out[i] & 1)
	out[i] = (out[i] >> 1) + 1;
      else
	out[i] = -(out[i] >> 1);
     } IACA_END
}
