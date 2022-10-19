#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int t1, const int32_t * in, int i, int t4, int16_t * out, int t0, int t3,
    ptrdiff_t pitch, int t2)
{
  for (i = 0; i < 4; i++)
    {
      if (!in[0] && !in[1] && !in[2] && !in[3])
	{
	  memset (out, 0, 4 * sizeof (out[0]));
	}
      else
	{
	  {
	    t0 = (in[0]) - (in[2]);
	    t1 = (in[0]) + (in[2]);
	    t2 = (t0);;
	    t0 = (((in[1]) + (in[3]) * 2 + 2) >> 2) + (in[1]);
	    t3 = (((in[1]) * 2 - (in[3]) + 2) >> 2) - (in[3]);
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
      in += 4;
      out += pitch;
    }
}
