#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int y, int x, const int w, IDWTELEM * prev, int use_median,
    IDWTELEM * line)
{
  IACA_START for (x = 0; x < w; x++)
    {
      if (x)
	{
	  if (use_median)
	    {
	      if (y && x + 1 < w)
		line[x] += mid_pred (line[x - 1], prev[x], prev[x + 1]);
	      else
		line[x] += line[x - 1];
	    }
	  else
	    {
	      if (y)
		line[x] +=
		  mid_pred (line[x - 1], prev[x],
			    line[x - 1] + prev[x] - prev[x - 1]);
	      else
		line[x] += line[x - 1];
	    }
	}
      else
	{
	  if (y)
	    line[x] += prev[x];
	}
     } IACA_END
}
