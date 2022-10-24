#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;

int
fn (int i, INTFLOAT * src1, INTFLOAT (*src0)[2], int n, INTFLOAT (*dst)[2])
{
  IACA_START for (i = 0; i < n; i++)
    {
      dst[i][0] = (int) (((int64_t) (src0[i][0]) * (src1[i]) + 0x8000) >> 16);
      dst[i][1] = (int) (((int64_t) (src0[i][1]) * (src1[i]) + 0x8000) >> 16);
}IACA_END}
