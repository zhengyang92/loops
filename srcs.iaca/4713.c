#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int x, uint16_t * dst, const uint8_t * src, const uint8_t * obmc_weight)
{
  for (x = 0; x < 32; x += 2)
    {
      dst[x] += src[x] * obmc_weight[x];
      dst[x + 1] += src[x + 1] * obmc_weight[x + 1];
    }
}
