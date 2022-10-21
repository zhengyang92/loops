#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int curr, float *a, int k, int *index)
{
  for (j = 0; j < k; ++j)
     { IACA_START
      if ((index[j] < 0) || a[curr] > a[index[j]])
	{
	  int swap = curr;
	  curr = index[j];
	  index[j] = swap;
	}
} IACA_END }
