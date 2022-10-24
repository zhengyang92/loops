#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t vo[23], const uint8_t * top, int i, uint8_t ve[23])
{
  IACA_START for (i = 0; i < 16 - 1; i++)
    {
      ve[16 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[16 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
     } IACA_END
}
