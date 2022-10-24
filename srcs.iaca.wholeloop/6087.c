#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int level[16], int i, int16_t * block, int total_coeff,
    const uint8_t * scantable)
{
  IACA_START for (; i < total_coeff; i++)
    {
      scantable--;
      ((int16_t *) block)[*scantable] = level[i];
     } IACA_END
}
