#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int sD[31], unsigned int di, int k, int rslope,
    unsigned int dmin)
{
  for (int i = -rslope; i <= rslope && abs (k) > rslope; i++)
    {
      if (dmin == sD[i + rslope])
	{
	  di = 1;
	  k = i;
	  break;
	}
    }
}
