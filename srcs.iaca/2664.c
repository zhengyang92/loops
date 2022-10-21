#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (const int16_t * ba, int16_t len, int16_t * x, int16_t * y, int32_t tmp,
    int16_t * signal)
{
  for (int i = 0; i < len; i++)
     { IACA_START
      tmp = ((int32_t) (((int16_t) (y[1])) * ((int16_t) (ba[3]))));
      tmp += ((int32_t) (((int16_t) (y[3])) * ((int16_t) (ba[4]))));
      tmp = (tmp >> 15);
      tmp += ((int32_t) (((int16_t) (y[0])) * ((int16_t) (ba[3]))));
      tmp += ((int32_t) (((int16_t) (y[2])) * ((int16_t) (ba[4]))));
      tmp = (tmp * 2);
      tmp += ((int32_t) (((int16_t) (signal[i])) * ((int16_t) (ba[0]))));
      tmp += ((int32_t) (((int16_t) (x[0])) * ((int16_t) (ba[1]))));
      tmp += ((int32_t) (((int16_t) (x[1])) * ((int16_t) (ba[2]))));
      x[1] = x[0];
      x[0] = signal[i];
      signal[i] = av_clip_intp2_c (tmp + 1024, 26) >> 11;
      y[2] = y[0];
      y[3] = y[1];
      if (tmp > 268435455)
	{
	  tmp = (2147483647);
	}
      else if (tmp < -268435456)
	{
	  tmp = (-2147483647 - 1);
	}
      else
	{
	  tmp = tmp * 8;
	}
      y[0] = tmp >> 16;
      y[1] = (tmp - (y[0] * (1 << 16))) >> 1;
     } IACA_END
}
