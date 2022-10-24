#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned short count[16], unsigned int len, int left)
{
  IACA_START for (len = 1; len <= 15; len++)
    {
      left <<= 1;
      left -= count[len];
      if (left < 0)
	return -1;
     } IACA_END
}
