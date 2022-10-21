#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int rc, int j, int coeff[16], int k)
{
  for (k = 0; k < (j + 1) / 2; k++)
     { IACA_START
      int tmp1 = coeff[k];
      int tmp2 = coeff[j - k - 1];
      coeff[k] = tmp1 + mul16 (rc, tmp2);
      coeff[j - k - 1] = tmp2 + mul16 (rc, tmp1);
} IACA_END }
