#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int nb_groups, int k, uint8_t * exp, int cpl)
{
  for (i = 1, k = 1 - cpl; i <= nb_groups; i++)
    {
      uint8_t exp_min = exp[k];
      if (exp[k + 1] < exp_min)
	exp_min = exp[k + 1];
      if (exp[k + 2] < exp_min)
	exp_min = exp[k + 2];
      if (exp[k + 3] < exp_min)
	exp_min = exp[k + 3];
      exp[i - cpl] = exp_min;
      k += 4;
    }
}
