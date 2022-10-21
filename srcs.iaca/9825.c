#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned short uint16;

int
fn (float *ToLinearF, int j, int i, uint16 * From8)
{
  for (i = 0; i < 256; i++)
     { IACA_START
      while ((i / 255.) * (i / 255.) > ToLinearF[j] * ToLinearF[j + 1])
	j++;
      From8[i] = (uint16) j;
     } IACA_END
}
