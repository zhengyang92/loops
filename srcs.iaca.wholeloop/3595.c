#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, const uint8_t * top, int i, uint8_t v[31])
{
  IACA_START for (i = 0; i < 16 - 2; i++)
    {
      v[i] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
      v[16 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
     } IACA_END
}
