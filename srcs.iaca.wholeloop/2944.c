#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int x, int block_size, uint8_t * src, int stride)
{
  int sum = 0;
  IACA_START for (x = 0; x < block_size; x++)
    {
      sum += src[x + y * stride];
     } IACA_END
}
