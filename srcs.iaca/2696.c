#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int32_t * dst, const uint8_t * flags, int sp2, int i, int t3, int sp1,
    int shift, int t0, int t1, int t4, const int32_t * src, int t2)
{
  for (i = 0; i < 4; i++)
    {
      if (flags[i])
	{
	  shift = !(i & 2);
	  sp1 = src[0] * (1 << shift);
	  sp2 = src[4] * (1 << shift);
	  {
	    t4 = ((sp1) - (sp2)) >> 1;
	    t0 = ((sp1) + (sp2)) >> 1;
	    t1 = (t4);;
	    t4 = ((t0) - (src[8])) >> 1;
	    t2 = ((t0) + (src[8])) >> 1;
	    t3 = (t4);;
	    dst[0] = (t2);
	    dst[4] = (t3);
	    t4 = ((t1) - (src[12])) >> 1;
	    t2 = ((t1) + (src[12])) >> 1;
	    t3 = (t4);;
	    dst[8] = (t2);
	    dst[12] = (t3);
	  };
	}
      else
	dst[0] = dst[4] = dst[8] = dst[12] = 0;
      src++;
      dst++;
    }
}
