#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int j, float *dst, int block_size, const uint16_t * src)
{
  for (j = 0; j < block_size; j++)
     { IACA_START
      dst[j] = src[j];
     } IACA_END
}
