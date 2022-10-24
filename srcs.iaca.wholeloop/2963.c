#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *block)
{
  IACA_START for (int i = 0; i < 8; i++)
    {
      if ((block[0x08 + i] | block[0x10 + i] | block[0x18 + i] |
	   block[0x20 + i] | block[0x28 + i] | block[0x30 + i] | block[0x38 +
								       i]) ==
	  0)
	{
	  block[0x08 + i] = block[i];
	  block[0x10 + i] = block[i];
	  block[0x18 + i] = block[i];
	  block[0x20 + i] = block[i];
	  block[0x28 + i] = block[i];
	  block[0x30 + i] = block[i];
	  block[0x38 + i] = block[i];
	}
      else
	{
	  idct_1d (block + i, 8);
	}
     } IACA_END
}
