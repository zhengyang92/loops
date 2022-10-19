#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t ff_table_4_3_value[32828], const double exp2_lut[4],
    int8_t ff_table_4_3_exp[32828], double pow43_val)
{
  for (int i = 1; i < ((8191 + 16) * 4); i++)
    {
      double f, fm;
      int e, m;
      double value = i / 4;
      if ((i & 3) == 0)
	pow43_val = value / 1.759 * cbrt (value);
      f = pow43_val * exp2_lut[i & 3];
      fm = frexp (f, &e);
      m = llrint (fm * (1LL << 31));
      e += 23 - 31 + 5 - 100;
      ff_table_4_3_value[i] = m;
      ff_table_4_3_exp[i] = -e;
    }
}
