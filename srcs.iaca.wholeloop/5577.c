#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int mrefs, uint8_t * cur, int x, int prefs, uint8_t * dst,
    uint8_t * prev2, uint8_t * next, int mode, uint8_t * prev,
    uint8_t * next2)
{
  IACA_START for (x = 0; x < 3; x++)
    {
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
      int spatial_pred = (c + e) >> 1;
      if (0)
	{
	  int spatial_score =
	    ((cur[mrefs - 1] - cur[prefs - 1]) >=
	     0 ? (cur[mrefs - 1] -
		  cur[prefs - 1]) : (-(cur[mrefs - 1] - cur[prefs - 1]))) +
	    ((c - e) >=
	     0 ? (c - e) : (-(c - e))) + ((cur[mrefs + 1] - cur[prefs + 1]) >=
					  0 ? (cur[mrefs + 1] -
					       cur[prefs +
						   1]) : (-(cur[mrefs + 1] -
							    cur[prefs +
								1]))) - 1;
	  {
	    int score =
	      ((cur[mrefs - 1 + (-1)] - cur[prefs - 1 - (-1)]) >=
	       0 ? (cur[mrefs - 1 + (-1)] -
		    cur[prefs - 1 - (-1)]) : (-(cur[mrefs - 1 + (-1)] -
						cur[prefs - 1 - (-1)]))) +
	      ((cur[mrefs + (-1)] - cur[prefs - (-1)]) >=
	       0 ? (cur[mrefs + (-1)] -
		    cur[prefs - (-1)]) : (-(cur[mrefs + (-1)] -
					    cur[prefs - (-1)]))) +
	      ((cur[mrefs + 1 + (-1)] - cur[prefs + 1 - (-1)]) >=
	       0 ? (cur[mrefs + 1 + (-1)] -
		    cur[prefs + 1 - (-1)]) : (-(cur[mrefs + 1 + (-1)] -
						cur[prefs + 1 - (-1)])));
	    if (score < spatial_score)
	      {
		spatial_score = score;
		spatial_pred = (cur[mrefs + (-1)] + cur[prefs - (-1)]) >> 1;
		{
		  int score =
		    ((cur[mrefs - 1 + (-2)] - cur[prefs - 1 - (-2)]) >=
		     0 ? (cur[mrefs - 1 + (-2)] -
			  cur[prefs - 1 - (-2)]) : (-(cur[mrefs - 1 + (-2)] -
						      cur[prefs - 1 -
							  (-2)]))) +
		    ((cur[mrefs + (-2)] - cur[prefs - (-2)]) >=
		     0 ? (cur[mrefs + (-2)] -
			  cur[prefs - (-2)]) : (-(cur[mrefs + (-2)] -
						  cur[prefs - (-2)]))) +
		    ((cur[mrefs + 1 + (-2)] - cur[prefs + 1 - (-2)]) >=
		     0 ? (cur[mrefs + 1 + (-2)] -
			  cur[prefs + 1 - (-2)]) : (-(cur[mrefs + 1 + (-2)] -
						      cur[prefs + 1 -
							  (-2)])));
		  if (score < spatial_score)
		    {
		      spatial_score = score;
		      spatial_pred =
			(cur[mrefs + (-2)] + cur[prefs - (-2)]) >> 1;
		    }
		}
	      }
	  }
	  {
	    int score =
	      ((cur[mrefs - 1 + (1)] - cur[prefs - 1 - (1)]) >=
	       0 ? (cur[mrefs - 1 + (1)] -
		    cur[prefs - 1 - (1)]) : (-(cur[mrefs - 1 + (1)] -
					       cur[prefs - 1 - (1)]))) +
	      ((cur[mrefs + (1)] - cur[prefs - (1)]) >=
	       0 ? (cur[mrefs + (1)] -
		    cur[prefs - (1)]) : (-(cur[mrefs + (1)] -
					   cur[prefs - (1)]))) + ((cur[mrefs +
								       1 +
								       (1)] -
								   cur[prefs +
								       1 -
								       (1)])
								  >=
								  0
								  ? (cur
								     [mrefs +
								      1 +
								      (1)] -
								     cur[prefs
									 + 1 -
									 (1)])
								  : (-
								     (cur
								      [mrefs +
								       1 +
								       (1)] -
								      cur
								      [prefs +
								       1 -
								       (1)])));
	    if (score < spatial_score)
	      {
		spatial_score = score;
		spatial_pred = (cur[mrefs + (1)] + cur[prefs - (1)]) >> 1;
		{
		  int score =
		    ((cur[mrefs - 1 + (2)] - cur[prefs - 1 - (2)]) >=
		     0 ? (cur[mrefs - 1 + (2)] -
			  cur[prefs - 1 - (2)]) : (-(cur[mrefs - 1 + (2)] -
						     cur[prefs - 1 - (2)]))) +
		    ((cur[mrefs + (2)] - cur[prefs - (2)]) >=
		     0 ? (cur[mrefs + (2)] -
			  cur[prefs - (2)]) : (-(cur[mrefs + (2)] -
						 cur[prefs - (2)]))) +
		    ((cur[mrefs + 1 + (2)] - cur[prefs + 1 - (2)]) >=
		     0 ? (cur[mrefs + 1 + (2)] -
			  cur[prefs + 1 - (2)]) : (-(cur[mrefs + 1 + (2)] -
						     cur[prefs + 1 - (2)])));
		  if (score < spatial_score)
		    {
		      spatial_score = score;
		      spatial_pred =
			(cur[mrefs + (2)] + cur[prefs - (2)]) >> 1;
		    }
		}
	      }
	  }
	}
      if (mode < 2)
	{
	  int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
	  int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
	  int max =
	    ((((d - e) > (d - c) ? (d - e) : (d - c))) >
	     (((b - c) > (f - e) ? (f - e) : (b - c))) ? (((d - e) >
							   (d - c) ? (d -
								      e) : (d
									    -
									    c)))
	     : (((b - c) > (f - e) ? (f - e) : (b - c))));
	  int min =
	    ((((d - e) > (d - c) ? (d - c) : (d - e))) >
	     (((b - c) > (f - e) ? (b - c) : (f - e))) ? (((b - c) >
							   (f - e) ? (b -
								      c) : (f
									    -
									    e)))
	     : (((d - e) > (d - c) ? (d - c) : (d - e))));
	  diff =
	    ((((diff) > (min) ? (diff) : (min))) >
	     (-max) ? (((diff) > (min) ? (diff) : (min))) : (-max));
	}
      if (spatial_pred > d + diff)
	spatial_pred = d + diff;
      else if (spatial_pred < d - diff)
	spatial_pred = d - diff;
      dst[0] = spatial_pred;
      dst++;
      cur++;
      prev++;
      next++;
      prev2++;
      next2++;
     } IACA_END
}
