#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t (*block)[64], int i)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      block[i][0] += 0x80 * 8 * 8;
      idct (block[i]);
     } IACA_END
}
