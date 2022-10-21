#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * src, int temp[64], int stride)
{
  for (x = 0; x < 8; x++)
     { IACA_START
      temp[x] = 4 * src[x];
      temp[x + 7 * 8] = 4 * src[x + 7 * stride];
     } IACA_END
}
