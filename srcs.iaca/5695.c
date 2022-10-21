#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float (*src0)[2], float (*dst)[2], int n, float *src1)
{
  for (i = 0; i < n; i++)
     { IACA_START
      dst[i][0] = src0[i][0] * src1[i];
      dst[i][1] = src0[i][1] * src1[i];
     } IACA_END
}
