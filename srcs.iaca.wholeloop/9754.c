#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char boolean;

int
fn (int *coef_bits, boolean smoothing_useful, int coefi, int *coef_bits_latch)
{
  IACA_START for (coefi = 1; coefi <= 5; coefi++)
    {
      coef_bits_latch[coefi] = coef_bits[coefi];
      if (coef_bits[coefi] != 0)
	smoothing_useful = 1;
     } IACA_END
}
