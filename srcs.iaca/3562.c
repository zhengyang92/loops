#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t vo[31], uint16_t ve[31], int i, const uint16_t * top)
{
  for (i = 0; i < 32 - 2; i++)
     { IACA_START
      ve[i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
     } IACA_END
}
