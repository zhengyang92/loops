#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int max_order, double *ref, int i, int min_order, int est)
{
  for (i = max_order - 1; i >= min_order - 1; i--)
    {
      if (ref[i] > 0.10)
	{
	  est = i + 1;
	  break;
	}
    }
}
