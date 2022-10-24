#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * src, int sum)
{
  int square_sum = 0;
  IACA_START for (x = 0; x < 8; x += 2)
    {
      sum += src[x];
      square_sum += src[x] * src[x];
     } IACA_END
}
