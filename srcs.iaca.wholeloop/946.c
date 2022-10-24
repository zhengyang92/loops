#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * S, const int src_w, int main_has_alpha, const int dr,
    const int sstep, const int dg, const int dst_w, int x, int jmax,
    const int dstep, const int sg, const int sr, uint8_t alpha, const int sa,
    int j, int is_straight, const int sb, uint8_t * d, const int da,
    const int db)
{
  IACA_START for (jmax = ((-x + dst_w) > (src_w) ? (src_w) : (-x + dst_w)); j < jmax;
       j++)
    {
      alpha = S[sa];
      if (main_has_alpha && alpha != 0 && alpha != 255)
	{
	  uint8_t alpha_d = d[da];
	  alpha =
	    ((((alpha) << 16) - ((alpha) << 9) +
	      (alpha)) / ((((alpha) + (alpha_d)) << 8) - ((alpha) +
							  (alpha_d)) -
			  (alpha_d) * (alpha)));
	}
      switch (alpha)
	{
	case 0:
	  break;
	case 255:
	  d[dr] = S[sr];
	  d[dg] = S[sg];
	  d[db] = S[sb];
	  break;
	default:
	  d[dr] =
	    is_straight
	    ? ((((d[dr] * (255 - alpha) + S[sr] * alpha) +
		 128) * 257) >> 16) : ((((((d[dr] * (255 - alpha)) + 128) *
					  257) >> 16) + S[sr]) >
				       (255) ? (255)
				       : (((((d[dr] * (255 - alpha)) +
					     128) * 257) >> 16) + S[sr]));
	  d[dg] =
	    is_straight
	    ? ((((d[dg] * (255 - alpha) + S[sg] * alpha) +
		 128) * 257) >> 16) : ((((((d[dg] * (255 - alpha)) + 128) *
					  257) >> 16) + S[sg]) >
				       (255) ? (255)
				       : (((((d[dg] * (255 - alpha)) +
					     128) * 257) >> 16) + S[sg]));
	  d[db] =
	    is_straight
	    ? ((((d[db] * (255 - alpha) + S[sb] * alpha) +
		 128) * 257) >> 16) : ((((((d[db] * (255 - alpha)) + 128) *
					  257) >> 16) + S[sb]) >
				       (255) ? (255)
				       : (((((d[db] * (255 - alpha)) +
					     128) * 257) >> 16) + S[sb]));
	}
      if (main_has_alpha)
	{
	  switch (alpha)
	    {
	    case 0:
	      break;
	    case 255:
	      d[da] = S[sa];
	      break;
	    default:
	      d[da] += (((((255 - d[da]) * S[sa]) + 128) * 257) >> 16);
	    }
	}
      d += dstep;
      S += sstep;
     } IACA_END
}
