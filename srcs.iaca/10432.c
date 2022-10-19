#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float r, float *a, int n, int i)
{
  for (i = 0; i < n; ++i)
    {
      r = r - a[i];
      if (r <= 0)
	return i;
    }
}
