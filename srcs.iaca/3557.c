#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t v[94], const uint16_t * left, int i, const uint16_t * top)
{
  for (i = 0; i < 32 - 2; i++)
     { IACA_START
      v[i * 2] = (left[i + 1] + left[i + 0] + 1) >> 1;
      v[i * 2 + 1] = (left[i + 2] + left[i + 1] * 2 + left[i + 0] + 2) >> 2;
      v[32 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
     } IACA_END
}
