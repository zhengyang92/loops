#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int coef, int i, int len, int *coefs, uint32_t ff_cbrt_tab_fixed[8192])
{
  IACA_START for (i = 0; i < len; i++)
    {
      coef = coefs[i];
      if (coef < 0)
	coef = -(int) ff_cbrt_tab_fixed[(-coef) & 8191];
      else
	coef = (int) ff_cbrt_tab_fixed[coef & 8191];
      coefs[i] = coef;
}IACA_END}
