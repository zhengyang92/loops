#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int i, int width, uint8_t * alpha, uint32_t alpha_and,
    const uint8_t * argb)
{
  IACA_START for (; i < width; ++i)
    {
      const uint32_t alpha_value = argb[4 * i];
      alpha[i] = alpha_value;
      alpha_and &= alpha_value;
}IACA_END}
