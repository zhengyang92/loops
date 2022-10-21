#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float expval_table_float[512][16], uint32_t expval_table_fixed[512][16],
    int value, int exponent)
{
  for (value = 0; value < 16; value++)
     { IACA_START
      double f =
	(double) value * powf (value, 1.0 / 3.0) * pow (2,
							(exponent -
							 400) * 0.25 + 23 +
							5);
      expval_table_fixed[exponent][value] =
	(long long int) (f >= 0 ? floor (f + 0.5) : ceil (f - 0.5));
      expval_table_float[exponent][value] = f;
} IACA_END }
