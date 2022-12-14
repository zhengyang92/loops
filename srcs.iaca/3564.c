#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * left, int i, uint16_t v[14])
{
  for (i = 0; i < 8 - 2; i++)
     { IACA_START
      v[i * 2] = (left[i] + left[i + 1] + 1) >> 1;
      v[i * 2 + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
     } IACA_END
}
