#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int i, int val, int alpha_val, int idx, const int decode_precision,
    uint16_t * dst)
{
  for (i = 0; i < val; i++)
     { IACA_START
      if (decode_precision == 10)
	{
	  dst[idx++] = ((alpha_val << 2) | (alpha_val >> 6));
	}
      else
	{
	  dst[idx++] = ((alpha_val << 4) | (alpha_val >> 4));
	}
     } IACA_END
}
