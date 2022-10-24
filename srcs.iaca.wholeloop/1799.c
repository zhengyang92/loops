#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (ptrdiff_t low_stride, ptrdiff_t high_stride, ptrdiff_t in_stride, int len,
    int16_t * low, int16_t * input, int16_t * high)
{
  IACA_START for (int i = 2; i < len - 2; i += 2)
    {
      low[(i >> 1) * low_stride] =
	av_clip_int16_c (input[i * in_stride] + input[(i + 1) * in_stride]);
      high[(i >> 1) * high_stride] =
	av_clip_int16_c (((-input[(i - 2) * in_stride] -
			   input[(i - 1) * in_stride] +
			   input[(i + 2) * in_stride] +
			   input[(i + 3) * in_stride] + 4) >> 3) + input[(i +
									  0) *
									 in_stride]
			 - input[(i + 1) * in_stride]);
}IACA_END}
