#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const float *src, int i, const float gain, float *dest,
    const uint16_t * offsets, int k, int group)
{
  IACA_START for (k = offsets[i]; k < offsets[i + 1]; k++)
    {
      dest[group * 128 + k] += gain * src[group * 128 + k];
     } IACA_END
}
