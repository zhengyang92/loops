#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, uint8_t v[14], int i)
{
  IACA_START for (i = 0; i < 8 - 2; i++)
    {
      v[i * 2] = (left[i] + left[i + 1] + 1) >> 1;
      v[i * 2 + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
     } IACA_END
}
