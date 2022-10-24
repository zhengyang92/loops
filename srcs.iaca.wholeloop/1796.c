#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t low_stride, int clip, const int16_t * high, int i,
    const int16_t * low, ptrdiff_t high_stride, ptrdiff_t out_stride,
    int16_t tmp, int len, int16_t * output)
{
  IACA_START for (i = 1; i < len - 1; i++)
    {
      tmp = (low[(i - 1) * low_stride] - low[(i + 1) * low_stride] + 4) >> 3;
      output[(2 * i + 0) * out_stride] =
	(tmp + low[i * low_stride] + high[i * high_stride]) >> 1;
      if (clip)
	output[(2 * i + 0) * out_stride] =
	  av_clip_uintp2_c (output[(2 * i + 0) * out_stride], clip);
      tmp = (low[(i + 1) * low_stride] - low[(i - 1) * low_stride] + 4) >> 3;
      output[(2 * i + 1) * out_stride] =
	(tmp + low[i * low_stride] - high[i * high_stride]) >> 1;
      if (clip)
	output[(2 * i + 1) * out_stride] =
	  av_clip_uintp2_c (output[(2 * i + 1) * out_stride], clip);
     } IACA_END
}
