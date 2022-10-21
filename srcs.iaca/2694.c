#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (const int32_t * in, int i, int t6, int t3, int t4, int t8, int t5, int t7,
    int16_t * out, int t0, int t1, ptrdiff_t pitch, int t2)
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
	    t1 = (in[0]) * 2;
	    t5 = (in[1]) * 2;
	    t0 = ((t1) - (t5)) >> 1;
	    t1 = ((t1) + (t5)) >> 1;
	    t5 = (t0);;
	    t0 = ((t1) - (in[2])) >> 1;
	    t1 = ((t1) + (in[2])) >> 1;
	    t3 = (t0);;
	    t0 = ((t5) - (in[3])) >> 1;
	    t5 = ((t5) + (in[3])) >> 1;
	    t7 = (t0);;
	    t0 = ((t1) - (in[4])) >> 1;
	    t1 = ((t1) + (in[4])) >> 1;
	    t2 = (t0);;
	    t0 = ((t3) - (in[5])) >> 1;
	    t3 = ((t3) + (in[5])) >> 1;
	    t4 = (t0);;
	    t0 = ((t5) - (in[6])) >> 1;
	    t5 = ((t5) + (in[6])) >> 1;
	    t6 = (t0);;
	    t0 = ((t7) - (in[7])) >> 1;
	    t7 = ((t7) + (in[7])) >> 1;
	    t8 = (t0);;
	    out[0] = (t1);
	    out[1] = (t2);
	    out[2] = (t3);
	    out[3] = (t4);
	    out[4] = (t5);
	    out[5] = (t6);
	    out[6] = (t7);
	    out[7] = (t8);
	  };
	}
      in += 8;
      out += pitch;
     } IACA_END
}
