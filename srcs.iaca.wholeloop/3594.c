#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, int i, const uint8_t * left, uint8_t v[15])
{
  IACA_START for (i = 0; i < 8 - 2; i++)
    {
      v[i] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
      v[8 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
     } IACA_END
}
