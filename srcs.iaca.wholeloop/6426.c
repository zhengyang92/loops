#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float lowest, int i, float workT[32])
{
  int low_indx = 0;
  IACA_START for (i = 0; i < 32; i++)
    {
      if (workT[i] < lowest)
	{
	  lowest = workT[i];
	  low_indx = i;
	}
     } IACA_END
}
