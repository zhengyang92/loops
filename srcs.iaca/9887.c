#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int i, uint32_t alpha_mask, int width, uint8_t * dst,
    const uint8_t * alpha)
{
  for (i = 0; i < width; ++i)
     { IACA_START
      const uint32_t alpha_value = alpha[i];
      dst[4 * i] = alpha_value;
      alpha_mask &= alpha_value;
} IACA_END }
