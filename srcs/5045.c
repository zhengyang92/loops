#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (int t1, const uint8_t * flags, const int32_t * in, int i, int t4,
    int16_t * out, int t0, int t3, ptrdiff_t pitch, int t2)
{
  for (i = 0; i < 4; i++)
    {
      if (flags[i])
	{
	  {
	    t4 = ((in[0]) - (in[4])) >> 1;
	    t0 = ((in[0]) + (in[4])) >> 1;
	    t1 = (t4);;
	    t4 = ((t0) - (in[8])) >> 1;
	    t2 = ((t0) + (in[8])) >> 1;
	    t3 = (t4);;
	    out[0 * pitch] = (t2);
	    out[1 * pitch] = (t3);
	    t4 = ((t1) - (in[12])) >> 1;
	    t2 = ((t1) + (in[12])) >> 1;
	    t3 = (t4);;
	    out[2 * pitch] = (t2);
	    out[3 * pitch] = (t3);
	  };
	}
      else
	out[0 * pitch] = out[1 * pitch] = out[2 * pitch] = out[3 * pitch] = 0;
      in++;
      out++;
    }
}
