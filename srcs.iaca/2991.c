#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (float c, int i, float *Xptr, float s, uint32_t stride, uint32_t len)
{
  for (i = 0; i < len - stride; i++)
     { IACA_START
      float x1 = Xptr[0];
      float x2 = Xptr[stride];
      Xptr[stride] = c * x2 + s * x1;
      *Xptr++ = c * x1 - s * x2;
} IACA_END }
