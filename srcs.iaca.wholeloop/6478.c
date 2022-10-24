#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float i2f, int i, float *src2, int csize, float *src0, float i0f,
    const float f_ict_params[4], float *src1, float i1f)
{
  IACA_START for (i = 0; i < csize; i++)
    {
      i0f = *src0 + (f_ict_params[0] * *src2);
      i1f = *src0 - (f_ict_params[1] * *src1) - (f_ict_params[2] * *src2);
      i2f = *src0 + (f_ict_params[3] * *src1);
      *src0++ = i0f;
      *src1++ = i1f;
      *src2++ = i2f;
     } IACA_END
}
