#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int t1, const int32_t * in, int i, ptrdiff_t pitch, int16_t * out, int t0,
    int t3, int t4, int t2)
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
	    t4 = ((in[0]) - (in[1])) >> 1;
	    t0 = ((in[0]) + (in[1])) >> 1;
	    t1 = (t4);;
	    t4 = ((t0) - (in[2])) >> 1;
	    t2 = ((t0) + (in[2])) >> 1;
	    t3 = (t4);;
	    out[0] = (t2);
	    out[1] = (t3);
	    t4 = ((t1) - (in[3])) >> 1;
	    t2 = ((t1) + (in[3])) >> 1;
	    t3 = (t4);;
	    out[2] = (t2);
	    out[3] = (t3);
	  };
	}
      in += 4;
      out += pitch;
    }
}
