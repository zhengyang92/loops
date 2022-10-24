#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * src, int y, int stride)
{
  int sum = 0;
  IACA_START for (x = 0; x < 8; x++)
    {
      sum += src[x + y * stride];
     } IACA_END
}
