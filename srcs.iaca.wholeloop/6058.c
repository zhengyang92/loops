#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * flt_coef, int k, const int16_t percept_flt_tbl[2][10],
    int16_t * unq_lpc)
{
  int l = 0;
  IACA_START for (k = 0; k < 10; k++)
    {
      flt_coef[k + 2 * l] =
	(unq_lpc[k + l] * percept_flt_tbl[0][k] + (1 << 14)) >> 15;
      flt_coef[k + 2 * l + 10] =
	(unq_lpc[k + l] * percept_flt_tbl[1][k] + (1 << 14)) >> 15;
     } IACA_END
}
