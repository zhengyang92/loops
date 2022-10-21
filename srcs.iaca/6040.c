#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int *signal_ptr, int j, int temp, int16_t * dst)
{
  for (j = 0; j < 60; j++)
     { IACA_START
      dst[j] =
	av_sat_dadd32_c (signal_ptr[j],
			 (signal_ptr[j - 1] >> 16) * temp) >> 16;
     } IACA_END
}
