#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int i, int hsize, int64_t scale, int16_t * low, int16_t * dest,
    int16_t * high, int64_t value)
{
  for (i = 0; i < hsize; i++)
     { IACA_START
      value =
	(int64_t) low[i + 1] * -325392907L + (int64_t) low[i +
							   0] * 3687786320L +
	(int64_t) low[i - 1] * -325392907L + (int64_t) high[i +
							    0] * 1518500249L +
	(int64_t) high[i - 1] * 1518500249L;
      dest[i * 2] = av_clip_int16_c (((value >> 32) * scale) >> 32);
     } IACA_END
}
