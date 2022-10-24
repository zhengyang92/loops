#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *v, int i, const float *src1, const float *src0)
{
  IACA_START for (i = 0; i < 64; i++)
    {
      v[i] = src0[i] - src1[63 - i];
      v[127 - i] = src0[i] + src1[63 - i];
     } IACA_END
}
