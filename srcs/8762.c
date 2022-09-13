#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int32_t * dst, int t1, const uint8_t * flags, int sp2, int i, int t6,
    int sp4, int sp3, int t8, int t5, int t7, int sp1, int shift, int t0,
    int t3, int t4, const int32_t * src, int t2)
{
  for (i = 0; i < 8; i++)
    {
      if (flags[i])
	{
	  shift = !(i & 4);
	  sp1 = src[0] * (1 << shift);
	  sp2 = src[8] * (1 << shift);
	  sp3 = src[16] * (1 << shift);
	  sp4 = src[24] * (1 << shift);
	  {
	    t1 = (sp1) * 2;
	    t5 = (sp2) * 2;
	    t0 = ((t1) - (t5)) >> 1;
	    t1 = ((t1) + (t5)) >> 1;
	    t5 = (t0);;
	    t0 = ((t1) - (sp3)) >> 1;
	    t1 = ((t1) + (sp3)) >> 1;
	    t3 = (t0);;
	    t0 = ((t5) - (sp4)) >> 1;
	    t5 = ((t5) + (sp4)) >> 1;
	    t7 = (t0);;
	    t0 = ((t1) - (src[32])) >> 1;
	    t1 = ((t1) + (src[32])) >> 1;
	    t2 = (t0);;
	    t0 = ((t3) - (src[40])) >> 1;
	    t3 = ((t3) + (src[40])) >> 1;
	    t4 = (t0);;
	    t0 = ((t5) - (src[48])) >> 1;
	    t5 = ((t5) + (src[48])) >> 1;
	    t6 = (t0);;
	    t0 = ((t7) - (src[56])) >> 1;
	    t7 = ((t7) + (src[56])) >> 1;
	    t8 = (t0);;
	    dst[0] = (t1);
	    dst[8] = (t2);
	    dst[16] = (t3);
	    dst[24] = (t4);
	    dst[32] = (t5);
	    dst[40] = (t6);
	    dst[48] = (t7);
	    dst[56] = (t8);
	  };
	}
      else
	dst[0] = dst[8] = dst[16] = dst[24] = dst[32] = dst[40] = dst[48] =
	  dst[56] = 0;
      src++;
      dst++;
    }
}
