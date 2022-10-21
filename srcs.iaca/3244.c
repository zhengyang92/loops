#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;

int
fn (INTFLOAT * v, const INTFLOAT * src0, int i, const INTFLOAT * src1)
{
  for (i = 0; i < 64; i++)
     { IACA_START
      v[i] = (int) (0x10U + src0[i] - src1[63 - i]) >> 5;
      v[127 - i] = (int) (0x10U + src0[i] + src1[63 - i]) >> 5;
} IACA_END }
