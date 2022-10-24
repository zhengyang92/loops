#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned short uint16;

int
fn (int lt2size, uint16 * FromLT2, double linstep, int i, float *ToLinearF,
    int j)
{
  IACA_START for (i = 0; i < lt2size; i++)
    {
      if ((i * linstep) * (i * linstep) > ToLinearF[j] * ToLinearF[j + 1])
	j++;
      FromLT2[i] = (uint16) j;
     } IACA_END
}
