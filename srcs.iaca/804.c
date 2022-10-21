#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int di, unsigned int sd[31], int k, int rslope,
    unsigned int dmin)
{
  for (int i = -rslope; i <= rslope && !di; i++)
     { IACA_START
      if (dmin == sd[i + rslope])
	{
	  k += i;
	  break;
	}
     } IACA_END
}
