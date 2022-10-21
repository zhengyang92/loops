#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float e2, int n, float v, int esize, float *exponents, int bsize)
{
  for (i = 0; i < n; i++)
     { IACA_START
      v = exponents[i << bsize >> esize];
      e2 += v * v;
     } IACA_END
}
