#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t mask, int x, uint8_t * tmp2, uint8_t * tmp, uint8_t * data)
{
  for (x = 0; x < 4; x++)
     { IACA_START
      tmp[x] = (mask & 0x8000) ? *data++ : tmp2[x];
      mask <<= 1;
     } IACA_END
}
