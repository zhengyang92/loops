#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *dst, int len, int *src1, int *src0)
{
  IACA_START for (i = 0; i < len; i++)
    {
      float r = src0[i] * (1.0f / (2.0f * (2147483647)));
      r += src1[i] * (1.0f / (2.0f * (2147483647)));
      dst[i] = r;
}IACA_END}
