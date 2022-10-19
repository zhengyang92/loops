#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;
typedef __int32_t int32_t;

int
fn (int row2, const uint8_t * flags, const int32_t * in, int i, int t6,
    int t3, int row4, int t8, int t5, ptrdiff_t pitch, int t7, int16_t * out,
    int row8, int t0, int t1, int t4, int t2)
{
  for (i = 0; i < 8; i++)
    {
      if (flags[i])
	{
	  {
	    t0 = (in[24]) + (((in[8]) * 4 - (in[24]) + 4) >> 3);
	    t5 = (in[8]) + ((-(in[8]) - (in[24]) * 4 + 4) >> 3);
	    t4 = (t0);;
	    t0 = (in[0]) - (t5);
	    t1 = (in[0]) + (t5);
	    t5 = (t0);;
	    t0 = (in[32]) - (in[40]);
	    t2 = (in[32]) + (in[40]);
	    t6 = (t0);;
	    t0 = (in[56]) - (in[48]);
	    t7 = (in[56]) + (in[48]);
	    t3 = (t0);;
	    t0 = (t4) - (in[16]);
	    t4 = (t4) + (in[16]);
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
	    out[pitch] = (((t2) + 1) >> 1);
	    out[row2] = (((t3) + 1) >> 1);
	    out[row2 + pitch] = (((t4) + 1) >> 1);
	    out[row4] = (((t5) + 1) >> 1);
	    out[row4 + pitch] = (((t6) + 1) >> 1);
	    out[row4 + row2] = (((t7) + 1) >> 1);
	    out[row8 - pitch] = (((t8) + 1) >> 1);
	  };
	}
      else
	{
	  out[0] = out[pitch] = out[row2] = out[row2 + pitch] = out[row4] =
	    out[row4 + pitch] = out[row4 + row2] = out[row8 - pitch] = 0;
	}
      in++;
      out++;
    }
}
