#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int y, uint8_t * src, int stride)
{
  int sum = 0;
  for (x = 0; x < 8; x++)
     { IACA_START
      sum += src[x + y * stride];
     } IACA_END
}
