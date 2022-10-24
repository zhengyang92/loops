#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (int i, int hsize, int64_t scale, int16_t * low, int16_t * dest,
    int16_t * high, int64_t value)
{
  IACA_START for (i = 0; i < hsize; i++)
    {
      value =
	(int64_t) low[i + 2] * -65078576L + (int64_t) low[i +
							  1] * 1583578880L +
	(int64_t) low[i + 0] * 1583578880L + (int64_t) low[i -
							   1] * -65078576L +
	(int64_t) high[i + 1] * 303700064L + (int64_t) high[i +
							    0] *
	-3644400640L + (int64_t) high[i - 1] * 303700064L;
      dest[i * 2 + 1] =
	av_clip_int16_c (((value >> 32) * (uint64_t) scale) >> 32);
     } IACA_END
}
