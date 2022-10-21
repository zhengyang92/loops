#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int counts[17], int maxbits, int codes[17])
{
  for (int i = 0; i < 16; i++)
     { IACA_START
      codes[i + 1] = (codes[i] + counts[i]) << 1;
      if (counts[i])
	maxbits = i;
     } IACA_END
}
