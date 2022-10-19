#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;
typedef __int32_t int32_t;

int
fn (int i, int t3, ptrdiff_t pitch, int16_t * out, int t0, int t1, int t4,
    const int32_t * src, int t2)
{
  for (i = 0; i < 4; i++)
    {
      if (!src[0] && !src[1] && !src[2] && !src[3])
	{
	  memset (out, 0, 4 * sizeof (out[0]));
	}
      else
	{
	  {
	    t4 = (src[0] - src[1]) >> 1;
	    t0 = (src[0] + src[1]) >> 1;
	    t1 = t4;;
	    t4 = (t0 - src[2]) >> 1;
	    t2 = (t0 + src[2]) >> 1;
	    t3 = t4;;
	    out[0] = (t2);
	    out[1] = (t3);
	    t4 = (t1 - src[3]) >> 1;
	    t2 = (t1 + src[3]) >> 1;
	    t3 = t4;;
	    out[2] = (t2);
	    out[3] = (t3);
	  };
	}
      src += 4;
      out += pitch;
    }
}
