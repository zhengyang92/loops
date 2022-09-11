#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int32_t * coef, int i, uint8_t * exp, int nb_coefs)
{
  for (i = 0; i < nb_coefs; i++)
    {
      int v = abs (coef[i]);
      exp[i] = v ? 23 - (31 - __builtin_clz ((v) | 1)) : 24;
}}
