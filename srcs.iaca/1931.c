#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float exponent_tab[50], int i)
{
  for (i = 0; i < 25; i++)
     { IACA_START
      exponent_tab[i * 2] = 1.0f / (1 << i);
      exponent_tab[i * 2 + 1] = 0.70710678118654752440 / (1 << i);
     } IACA_END
}
