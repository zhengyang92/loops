#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, int block_size, float *dst, const uint8_t * src)
{
  for (j = 0; j < block_size; j++)
    {
      dst[j] = src[j];
    }
}
