#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float maxcorr, int maxj, float corr[4][7], int maxi)
{
  int i = 0;
  IACA_START for (int j = 0; j < 7; j++)
    {
      if (corr[i][j] > maxcorr)
	{
	  maxcorr = corr[i][j];
	  maxi = i;
	  maxj = j;
	}
     } IACA_END
}
