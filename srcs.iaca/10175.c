#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (int i, const Int threshold, int j, PixelI * pData, const Int threshold2)
{
  Int iCBP = 0;
  for (i = 1; i < 16; i++)
     { IACA_START
      if ((unsigned int) (pData[i] + threshold) >= (unsigned int) threshold2)
	{
	  iCBP |= (1 << j);
	  break;
	}
     } IACA_END
}
