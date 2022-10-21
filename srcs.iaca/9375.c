#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (int32_t * dst, int t1, const uint8_t * flags, int i, int t0, int t3,
    int t4, const int32_t * src, int t2)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      if (flags[i])
	{
	  {
	    t0 = src[0] - src[8];
	    t1 = src[0] + src[8];
	    t2 = t0;;
	    t0 = ((src[4] + src[12] * 2 + 2) >> 2) + src[4];
	    t3 = ((src[4] * 2 - src[12] + 2) >> 2) - src[12];
	    t4 = t0;;
	    t0 = t1 - t4;
	    t1 = t1 + t4;
	    t4 = t0;;
	    t0 = t2 - t3;
	    t2 = t2 + t3;
	    t3 = t0;;
	    dst[0] = (t1);
	    dst[4] = (t2);
	    dst[8] = (t3);
	    dst[12] = (t4);
	  };
	}
      else
	dst[0] = dst[4] = dst[8] = dst[12] = 0;
      src++;
      dst++;
     } IACA_END
}
