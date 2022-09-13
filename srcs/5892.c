#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (ptrdiff_t low_stride, int clip, int i, ptrdiff_t high_stride,
    ptrdiff_t out_stride, int16_t tmp, int len, int16_t * output,
    int16_t * low, int16_t * high)
{
  for (i = 0; i < len; i++)
    {
      if (i == 0)
	{
	  tmp =
	    (11 * low[0 * low_stride] - 4 * low[1 * low_stride] +
	     low[2 * low_stride] + 4) >> 3;
	  output[(2 * i + 0) * out_stride] =
	    (tmp + high[0 * high_stride]) >> 1;
	}
      else if (i == len - 1)
	{
	  tmp =
	    (5 * low[i * low_stride] + 4 * low[(i - 1) * low_stride] -
	     low[(i - 2) * low_stride] + 4) >> 3;
	  output[(2 * i + 0) * out_stride] =
	    (tmp + high[i * high_stride]) >> 1;
	}
      else
	{
	  tmp =
	    (low[(i - 1) * low_stride] - low[(i + 1) * low_stride] + 4) >> 3;
	  output[(2 * i + 0) * out_stride] =
	    (tmp + low[i * low_stride] + high[i * high_stride]) >> 1;
	}
      if (clip)
	output[(2 * i + 0) * out_stride] =
	  av_clip_uintp2_c (output[(2 * i + 0) * out_stride], clip);
      if (i == 0)
	{
	  tmp =
	    (5 * low[0 * low_stride] + 4 * low[1 * low_stride] -
	     low[2 * low_stride] + 4) >> 3;
	  output[(2 * i + 1) * out_stride] =
	    (tmp - high[0 * high_stride]) >> 1;
	}
      else if (i == len - 1)
	{
	  tmp =
	    (11 * low[i * low_stride] - 4 * low[(i - 1) * low_stride] +
	     low[(i - 2) * low_stride] + 4) >> 3;
	  output[(2 * i + 1) * out_stride] =
	    (tmp - high[i * high_stride]) >> 1;
	}
      else
	{
	  tmp =
	    (low[(i + 1) * low_stride] - low[(i - 1) * low_stride] + 4) >> 3;
	  output[(2 * i + 1) * out_stride] =
	    (tmp + low[i * low_stride] - high[i * high_stride]) >> 1;
	}
      if (clip)
	output[(2 * i + 1) * out_stride] =
	  av_clip_uintp2_c (output[(2 * i + 1) * out_stride], clip);
    }
}
