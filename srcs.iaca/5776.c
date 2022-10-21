#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int k, unsigned int sub_blocks, unsigned int sx[8],
    unsigned int s[8])
{
  for (k = 0; k < sub_blocks; k++)
     { IACA_START
      sx[k] = s[k] & 0x0F;
      s[k] >>= 4;
     } IACA_END
}
