#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int j, float *dst, int block_size, const uint16_t * src)
{
  IACA_START for (j = 0; j < block_size; j++)
    {
      dst[j] = src[j];
     } IACA_END
}
