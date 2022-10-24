#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t vo[23], uint16_t ve[23], int i, const uint16_t * top)
{
  IACA_START for (i = 0; i < 16 - 1; i++)
    {
      ve[16 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[16 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
     } IACA_END
}
