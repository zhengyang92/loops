#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int32_t * dst, const uint8_t * flags, int i, int t6, int t3, int t8,
    int t5, int t7, int t0, int t1, int t4, const int32_t * src, int t2)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      if (flags[i])
	{
	  {
	    t0 = (src[24]) + (((src[8]) * 4 - (src[24]) + 4) >> 3);
	    t5 = (src[8]) + ((-(src[8]) - (src[24]) * 4 + 4) >> 3);
	    t4 = (t0);;
	    t0 = (src[0]) - (t5);
	    t1 = (src[0]) + (t5);
	    t5 = (t0);;
	    t0 = (src[32]) - (src[40]);
	    t2 = (src[32]) + (src[40]);
	    t6 = (t0);;
	    t0 = (src[56]) - (src[48]);
	    t7 = (src[56]) + (src[48]);
	    t3 = (t0);;
	    t0 = (t4) - (src[16]);
	    t4 = (t4) + (src[16]);
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
     } IACA_END
}
