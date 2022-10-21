#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int w, uint8_t * next, int mrefs, int mrefs4, int interpol, uint8_t * cur,
    int x, int mrefs3, int prefs, uint8_t * next2, int prefs2,
    const uint16_t coef_hf[3], const uint16_t coef_lf[2], int mrefs2,
    uint8_t * prev2, uint8_t * prev, int clip_max, int prefs4,
    const uint16_t coef_sp[2], int prefs3, uint8_t * dst)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int c = cur[mrefs];
      int d = (prev2[0] + next2[0]) >> 1;
      int e = cur[prefs];
      int temporal_diff0 =
	((prev2[0] - next2[0]) >=
	 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0])));
      int temporal_diff1 =
	(((prev[mrefs] - c) >=
	  0 ? (prev[mrefs] - c) : (-(prev[mrefs] - c))) + ((prev[prefs] -
							    e) >=
							   0 ? (prev[prefs] -
								e)
							   : (-
							      (prev[prefs] -
							       e)))) >> 1;
      int temporal_diff2 =
	(((next[mrefs] - c) >=
	  0 ? (next[mrefs] - c) : (-(next[mrefs] - c))) + ((next[prefs] -
							    e) >=
							   0 ? (next[prefs] -
								e)
							   : (-
							      (next[prefs] -
							       e)))) >> 1;
      int diff =
	((((temporal_diff0 >> 1) >
	   (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) >
	 (temporal_diff2)
	 ? (((temporal_diff0 >> 1) >
	     (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1)))
	 : (temporal_diff2));
      if (!diff)
	{
	  dst[0] = d;
	}
      else
	{
	  int b = ((prev2[mrefs2] + next2[mrefs2]) >> 1) - c;
	  int f = ((prev2[prefs2] + next2[prefs2]) >> 1) - e;
	  int dc = d - c;
	  int de = d - e;
	  int max =
	    ((((de) > (dc) ? (de) : (dc))) >
	     (((b) > (f) ? (f) : (b))) ? (((de) >
					   (dc) ? (de) : (dc))) : (((b) >
								    (f) ? (f)
								    : (b))));
	  int min =
	    ((((de) > (dc) ? (dc) : (de))) >
	     (((b) > (f) ? (b) : (f))) ? (((b) > (f) ? (b) : (f))) : (((de) >
								       (dc)
								       ? (dc)
								       :
								       (de))));
	  diff =
	    ((((diff) > (min) ? (diff) : (min))) >
	     (-max) ? (((diff) > (min) ? (diff) : (min))) : (-max));
	  if (((c - e) >= 0 ? (c - e) : (-(c - e))) > temporal_diff0)
	    {
	      interpol =
		(((coef_hf[0] * (prev2[0] + next2[0]) -
		   coef_hf[1] * (prev2[mrefs2] + next2[mrefs2] +
				 prev2[prefs2] + next2[prefs2]) +
		   coef_hf[2] * (prev2[mrefs4] + next2[mrefs4] +
				 prev2[prefs4] + next2[prefs4])) >> 2) +
		 coef_lf[0] * (c + e) - coef_lf[1] * (cur[mrefs3] +
						      cur[prefs3])) >> 13;
	    }
	  else
	    {
	      interpol =
		(coef_sp[0] * (c + e) -
		 coef_sp[1] * (cur[mrefs3] + cur[prefs3])) >> 13;
	    }
	  if (interpol > d + diff)
	    interpol = d + diff;
	  else if (interpol < d - diff)
	    interpol = d - diff;
	  dst[0] = av_clip_c (interpol, 0, clip_max);
	}
      dst++;
      cur++;
      prev++;
      next++;
      prev2++;
      next2++;
     } IACA_END
}
