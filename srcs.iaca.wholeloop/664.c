#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, float *dst, int block_size, const uint8_t * src)
{
  IACA_START for (j = 0; j < block_size; j++)
    {
      dst[j] = src[j];
     } IACA_END
}
