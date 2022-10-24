#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int counts[17], int maxbits, int codes[17])
{
  IACA_START for (int i = 0; i < 16; i++)
    {
      codes[i + 1] = (codes[i] + counts[i]) << 1;
      if (counts[i])
	maxbits = i;
     } IACA_END
}
