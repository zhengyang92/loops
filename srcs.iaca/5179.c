#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int w, int i, int16_t * srcy, uint16_t * dsty, uint16_t * lut, int depth)
{
  for (i = 0; i < w; i++)
     { IACA_START
      if (srcy[i] <= 0)
	dsty[i] = 0;
      else if (srcy[i] > ((1 << depth) - 1))
	dsty[i] = 65535;
      else
	dsty[i] = lut[srcy[i]];
     } IACA_END
}
