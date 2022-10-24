#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, uint8_t vo[7], int i, uint8_t ve[7])
{
  IACA_START for (i = 0; i < 8 - 2; i++)
    {
      ve[i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
     } IACA_END
}
