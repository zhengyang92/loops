#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * src, int i, int add)
{
  int shift = 7;
  for (i = 0; i < 4; i++)
     { IACA_START
      do
	{
	  int c0 = src[0 * 4] + src[2 * 4];
	  int c1 = src[2 * 4] + src[3 * 4];
	  int c2 = src[0 * 4] - src[3 * 4];
	  int c3 = 74 * src[1 * 4];
	  (src[2 * 4]) =
	    av_clip_int16_c (((74 * (src[0 * 4] - src[2 * 4] + src[3 * 4])) +
			      add) >> shift);
	  (src[0 * 4]) =
	    av_clip_int16_c (((29 * c0 + 55 * c1 + c3) + add) >> shift);
	  (src[1 * 4]) =
	    av_clip_int16_c (((55 * c2 - 29 * c1 + c3) + add) >> shift);
	  (src[3 * 4]) =
	    av_clip_int16_c (((55 * c0 + 29 * c2 - c3) + add) >> shift);
	}
      while (0);
      src++;
     } IACA_END
}
