#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t dmin, int k, uint64_t di, int rslope, uint64_t sd[31])
{
  for (int i = -rslope; i <= rslope && !di; i++)
    {
      if (dmin == sd[i + rslope])
	{
	  k += i;
	  break;
	}
    }
}
