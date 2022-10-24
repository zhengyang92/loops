#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t ff_scale_factor_modshift[64])
{
  IACA_START for (int i = 0; i < 64; i++)
    {
      int shift, mod;
      shift = i / 3;
      mod = i % 3;
      ff_scale_factor_modshift[i] = mod | (shift << 2);
}IACA_END}
