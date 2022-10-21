#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, const uint8_t * top, uint8_t v[94], int i)
{
  for (i = 0; i < 32 - 2; i++)
     { IACA_START
      v[i * 2] = (left[i + 1] + left[i + 0] + 1) >> 1;
      v[i * 2 + 1] = (left[i + 2] + left[i + 1] * 2 + left[i + 0] + 2) >> 2;
      v[32 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
     } IACA_END
}
