#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double pow43_lut[16], uint32_t expval_table_fixed[512][16], int value,
    double exp2_val, int exponent)
{
  IACA_START for (value = 0; value < 16; value++)
    {
      double f = pow43_lut[value] * exp2_val;
      expval_table_fixed[exponent][value] =
	(f < 0xFFFFFFFF ? llrint (f) : 0xFFFFFFFF);
}IACA_END}
