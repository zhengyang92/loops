#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * flags, const int32_t * in, int i, int t6, int t3, int t4,
    int t8, int t5, int t7, int16_t * out, int t0, int t1, ptrdiff_t pitch,
    int t2)
{
  for (i = 0; i < 8; i++)
    {
      if (flags[i])
	{
	  {
	    t1 = in[0] << 1;
	    t5 = in[8] << 1;
	    t0 = (t1 - t5) >> 1;
	    t1 = (t1 + t5) >> 1;
	    t5 = t0;;
	    t0 = (t1 - in[16]) >> 1;
	    t1 = (t1 + in[16]) >> 1;
	    t3 = t0;;
	    t0 = (t5 - in[24]) >> 1;
	    t5 = (t5 + in[24]) >> 1;
	    t7 = t0;;
	    t0 = (t1 - in[32]) >> 1;
	    t1 = (t1 + in[32]) >> 1;
	    t2 = t0;;
	    t0 = (t3 - in[40]) >> 1;
	    t3 = (t3 + in[40]) >> 1;
	    t4 = t0;;
	    t0 = (t5 - in[48]) >> 1;
	    t5 = (t5 + in[48]) >> 1;
	    t6 = t0;;
	    t0 = (t7 - in[56]) >> 1;
	    t7 = (t7 + in[56]) >> 1;
	    t8 = t0;;
	    out[0 * pitch] = (t1);
	    out[1 * pitch] = (t2);
	    out[2 * pitch] = (t3);
	    out[3 * pitch] = (t4);
	    out[4 * pitch] = (t5);
	    out[5 * pitch] = (t6);
	    out[6 * pitch] = (t7);
	    out[7 * pitch] = (t8);
	  };
	}
      else
	out[0 * pitch] = out[1 * pitch] = out[2 * pitch] = out[3 * pitch] =
	  out[4 * pitch] = out[5 * pitch] = out[6 * pitch] = out[7 * pitch] =
	  0;
      in++;
      out++;
    }
}
