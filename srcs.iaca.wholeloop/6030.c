#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int f1[6], int16_t * lpc, int i, int f2[6])
{
  IACA_START for (i = 0; i < 10 / 2; i++)
    {
      int64_t ff1 = f1[i + 1] + f1[i];
      int64_t ff2 = f2[i + 1] - f2[i];
      lpc[i] = av_clipl_int32_c (((ff1 + ff2) << 3) + (1 << 15)) >> 16;
      lpc[10 - i - 1] =
	av_clipl_int32_c (((ff1 - ff2) << 3) + (1 << 15)) >> 16;
     } IACA_END
}
