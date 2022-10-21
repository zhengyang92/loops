#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t ve[11], uint16_t vo[11], int i, const uint16_t * top)
{
  for (i = 0; i < 8 - 1; i++)
     { IACA_START
      ve[8 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[8 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
     } IACA_END
}
