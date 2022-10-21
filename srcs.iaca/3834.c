#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * dstV, int width, int i, int16_t * dstU)
{
  for (i = 0; i < width; i++)
     { IACA_START
      dstU[i] =
	(((dstU[i]) > (30775) ? (30775) : (dstU[i])) * 4663 - 9289992) >> 12;
      dstV[i] =
	(((dstV[i]) > (30775) ? (30775) : (dstV[i])) * 4663 - 9289992) >> 12;
     } IACA_END
}
