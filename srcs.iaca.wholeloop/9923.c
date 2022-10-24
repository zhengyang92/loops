#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int distribution[32], int k, int16_t out[16])
{
  IACA_START for (k = 0; k < 16; ++k)
    {
      const int v = abs (out[k]) >> 3;
      const int clipped_value = clip_max (v, 31);
      ++distribution[clipped_value];
}IACA_END}
