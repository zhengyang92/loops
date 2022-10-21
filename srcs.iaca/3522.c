#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * src, int sum)
{
  int square_sum = 0;
  for (x = 0; x < 8; x += 2)
     { IACA_START
      sum += src[x];
      square_sum += src[x] * src[x];
     } IACA_END
}
