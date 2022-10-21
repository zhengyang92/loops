#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (int t1, const int32_t * in, int i, int t6, int t8, int t5,
    ptrdiff_t pitch, int t7, int16_t * out, int t0, int t3, int t4, int t2)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      if (!in[0] && !in[1] && !in[2] && !in[3] && !in[4] && !in[5] && !in[6]
	  && !in[7])
	{
	  memset (out, 0, 8 * sizeof (out[0]));
	}
      else
	{
	  {
	    t0 = (in[3]) + (((in[1]) * 4 - (in[3]) + 4) >> 3);
	    t5 = (in[1]) + ((-(in[1]) - (in[3]) * 4 + 4) >> 3);
	    t4 = (t0);;
	    t0 = (in[0]) - (t5);
	    t1 = (in[0]) + (t5);
	    t5 = (t0);;
	    t0 = (in[4]) - (in[5]);
	    t2 = (in[4]) + (in[5]);
	    t6 = (t0);;
	    t0 = (in[7]) - (in[6]);
	    t7 = (in[7]) + (in[6]);
	    t3 = (t0);;
	    t0 = (t4) - (in[2]);
	    t4 = (t4) + (in[2]);
	    t8 = (t0);;
	    t0 = (t1) - (t2);
	    t1 = (t1) + (t2);
	    t2 = (t0);;
	    t0 = (((t4) + (t3) * 2 + 2) >> 2) + (t4);
	    t3 = (((t4) * 2 - (t3) + 2) >> 2) - (t3);
	    t4 = (t0);;
	    t0 = (t5) - (t6);
	    t5 = (t5) + (t6);
	    t6 = (t0);;
	    t0 = (((t8) + (t7) * 2 + 2) >> 2) + (t8);
	    t7 = (((t8) * 2 - (t7) + 2) >> 2) - (t7);
	    t8 = (t0);;
	    t0 = (t1) - (t4);
	    t1 = (t1) + (t4);
	    t4 = (t0);;
	    t0 = (t2) - (t3);
	    t2 = (t2) + (t3);
	    t3 = (t0);;
	    t0 = (t5) - (t8);
	    t5 = (t5) + (t8);
	    t8 = (t0);;
	    t0 = (t6) - (t7);
	    t6 = (t6) + (t7);
	    t7 = (t0);;
	    out[0] = (((t1) + 1) >> 1);
	    out[1] = (((t2) + 1) >> 1);
	    out[2] = (((t3) + 1) >> 1);
	    out[3] = (((t4) + 1) >> 1);
	    out[4] = (((t5) + 1) >> 1);
	    out[5] = (((t6) + 1) >> 1);
	    out[6] = (((t7) + 1) >> 1);
	    out[7] = (((t8) + 1) >> 1);
	  };
	}
      in += 8;
      out += pitch;
     } IACA_END
}
