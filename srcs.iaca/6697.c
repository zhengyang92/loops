#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float c, int i, float *Xptr, float s, unsigned int len,
    unsigned int stride)
{
  for (i = 0; i < len - stride; i++)
     { IACA_START
      float x1, x2;
      x1 = Xptr[0];
      x2 = Xptr[stride];
      Xptr[stride] = c * x2 + s * x1;
      *Xptr++ = c * x1 - s * x2;
} IACA_END }
