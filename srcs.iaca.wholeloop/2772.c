#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int max_order, int zero_shift, int i, int min_shift, int max_shift,
    int min_order, int32_t (*coefs)[32], int *shift, double lpc[32][32],
    int precision)
{
  IACA_START for (i = min_order - 1; i < max_order; i++)
    {
      quantize_lpc_coefs (lpc[i], i + 1, precision, coefs[i], &shift[i],
			  min_shift, max_shift, zero_shift);
     } IACA_END
}
