#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int32_t * coef, int i, int nb_coefs, uint8_t * exp)
{
  for (i = 0; i < nb_coefs; i++)
     { IACA_START
      int v = abs (coef[i]);
      exp[i] = v ? 23 - (31 - __builtin_clz ((v) | 1)) : 24;
} IACA_END }
