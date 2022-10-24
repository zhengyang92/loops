#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float pow_table[2048])
{
  IACA_START for (int i = 1; i < 513; i++)
    {
      double tmp = exp2 (-i / 2048.0);
      pow_table[i] = tmp;
      pow_table[1024 - i] = 0.70710678118654752440 / tmp;
      pow_table[1024 + i] = tmp * 0.70710678118654752440;
      pow_table[2048 - i] = 0.5 / tmp;
}IACA_END}
