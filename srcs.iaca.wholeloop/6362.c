#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t * src, int limit2, int add, const int8_t transform[32][32])
{
  int shift = 7;
  IACA_START for (i = 0; i < 4; i++)
    {
      do
	{
	  const int e0 =
	    transform[8 * 0][0] * src[0 * 4] +
	    transform[8 * 2][0] * src[2 * 4];
	  const int e1 =
	    transform[8 * 0][1] * src[0 * 4] +
	    transform[8 * 2][1] * src[2 * 4];
	  const int o0 =
	    transform[8 * 1][0] * src[1 * 4] +
	    transform[8 * 3][0] * src[3 * 4];
	  const int o1 =
	    transform[8 * 1][1] * src[1 * 4] +
	    transform[8 * 3][1] * src[3 * 4];
	  (src[0 * 4]) = av_clip_int16_c (((e0 + o0) + add) >> shift);
	  (src[1 * 4]) = av_clip_int16_c (((e1 + o1) + add) >> shift);
	  (src[2 * 4]) = av_clip_int16_c (((e1 - o1) + add) >> shift);
	  (src[3 * 4]) = av_clip_int16_c (((e0 - o0) + add) >> shift);
	}
      while (0);
      if (limit2 < 4 && i % 4 == 0 && !!i)
	limit2 -= 4;
      src++;
     } IACA_END
}
