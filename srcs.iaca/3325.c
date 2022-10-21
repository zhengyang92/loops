#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int y, int x, const int w, int use_median, IDWTELEM * src, int stride)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int i = x + y * stride;
      if (x)
	{
	  if (use_median)
	    {
	      if (y && x + 1 < w)
		src[i] +=
		  mid_pred (src[i - 1], src[i - stride], src[i - stride + 1]);
	      else
		src[i] += src[i - 1];
	    }
	  else
	    {
	      if (y)
		src[i] +=
		  mid_pred (src[i - 1], src[i - stride],
			    src[i - 1] + src[i - stride] - src[i - 1 -
							       stride]);
	      else
		src[i] += src[i - 1];
	    }
	}
      else
	{
	  if (y)
	    src[i] += src[i - stride];
	}
     } IACA_END
}
