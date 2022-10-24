#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *buf)
{
  IACA_START for (i = 0; i < 256; i++)
    {
      do
	{
	  float SWAP_tmp = buf[511 - i];
	  buf[511 - i] = buf[i];
	  buf[i] = SWAP_tmp;
	}
      while (0);
     } IACA_END
}
