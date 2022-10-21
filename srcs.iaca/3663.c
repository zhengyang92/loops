#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float v, int n, float e2, int esize, float *exponents, int bsize)
{
  for (i = 0; i < n; i++)
     { IACA_START
      v = exponents[i << bsize >> esize];
      e2 += v * v;
     } IACA_END
}
