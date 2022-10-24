#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (int i, const Int threshold, int j, PixelI * pData, const Int threshold2)
{
  Int iCBP = 0;
  IACA_START for (i = 1; i < 16; i++)
    {
      if ((unsigned int) (pData[i] + threshold) >= (unsigned int) threshold2)
	{
	  iCBP |= (1 << j);
	  break;
	}
     } IACA_END
}
