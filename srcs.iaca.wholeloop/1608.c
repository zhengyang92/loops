#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int nb_groups, int k, uint8_t * exp, int cpl)
{
  IACA_START for (i = 1, k = 1 - cpl; i <= nb_groups; i++)
    {
      uint8_t exp_min = exp[k];
      if (exp[k + 1] < exp_min)
	exp_min = exp[k + 1];
      exp[i - cpl] = exp_min;
      k += 2;
     } IACA_END
}
