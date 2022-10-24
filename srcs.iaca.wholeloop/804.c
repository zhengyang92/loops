#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int di, unsigned int sd[31], int k, int rslope,
    unsigned int dmin)
{
  IACA_START for (int i = -rslope; i <= rslope && !di; i++)
    {
      if (dmin == sd[i + rslope])
	{
	  k += i;
	  break;
	}
     } IACA_END
}
