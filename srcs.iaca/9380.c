#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int row2, const uint8_t * flags, const int32_t * in, int i, int t3,
    int t4, int16_t * out, int t0, int t1, ptrdiff_t pitch, int t2)
{
  for (i = 0; i < 4; i++)
    {
      if (flags[i])
	{
	  {
	    t0 = in[0] - in[8];
	    t1 = in[0] + in[8];
	    t2 = t0;;
	    t0 = ((in[4] + in[12] * 2 + 2) >> 2) + in[4];
	    t3 = ((in[4] * 2 - in[12] + 2) >> 2) - in[12];
	    t4 = t0;;
	    t0 = t1 - t4;
	    t1 = t1 + t4;
	    t4 = t0;;
	    t0 = t2 - t3;
	    t2 = t2 + t3;
	    t3 = t0;;
	    out[0] = ((t1 + 1) >> 1);
	    out[pitch] = ((t2 + 1) >> 1);
	    out[row2] = ((t3 + 1) >> 1);
	    out[row2 + pitch] = ((t4 + 1) >> 1);
	  };
	}
      else
	{
	  out[0] = out[pitch] = out[row2] = out[row2 + pitch] = 0;
	}
      in++;
      out++;
    }
}
