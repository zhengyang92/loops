#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t table_4_3_value[32828], int i, int8_t table_4_3_exp[32828])
{
  for (i = 1; i < (8191 + 16) * 4; i++)
    {
      double value = i / 4;
      double f, fm;
      int e, m;
      f = value * powf (value, 1.0 / 3.0) * pow (2, (i & 3) * 0.25);
      fm = frexp (f, &e);
      m = (uint32_t) (fm * (1LL << 31) + 0.5);
      e += 23 - 31 + 5 - 100;
      table_4_3_value[i] = m;
      table_4_3_exp[i] = -e;
}}
