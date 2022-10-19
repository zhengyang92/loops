#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (int i, int t3, int t4, int16_t * out, int t0, int t1, ptrdiff_t pitch,
    const int32_t * src, int t2)
{
  for (i = 0; i < 4; i++)
    {
      if (!src[0] && !src[1] && !src[2] && !src[3])
	{
	  out[0] = out[1] = out[2] = out[3] = 0;
	}
      else
	{
	  {
	    t0 = (src[0]) - (src[2]);
	    t1 = (src[0]) + (src[2]);
	    t2 = (t0);;
	    t0 = (((src[1]) + (src[3]) * 2 + 2) >> 2) + (src[1]);
	    t3 = (((src[1]) * 2 - (src[3]) + 2) >> 2) - (src[3]);
	    t4 = (t0);;
	    t0 = (t1) - (t4);
	    t1 = (t1) + (t4);
	    t4 = (t0);;
	    t0 = (t2) - (t3);
	    t2 = (t2) + (t3);
	    t3 = (t0);;
	    out[0] = (((t1) + 1) >> 1);
	    out[1] = (((t2) + 1) >> 1);
	    out[2] = (((t3) + 1) >> 1);
	    out[3] = (((t4) + 1) >> 1);
	  };
	}
      src += 4;
      out += pitch;
    }
}
