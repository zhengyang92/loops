#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int max_sb, const unsigned char *alloc, int i)
{
  for (i = 0; i < max_sb; i++)
     { IACA_START
      alloc += 1 << alloc[0];
     } IACA_END
}
