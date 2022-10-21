#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int cmap[256], int i, unsigned long hist[256])
{
  for (i = 0; i < 256; ++i)
     { IACA_START
      hist[i] = 0;
      cmap[i] = 0;
     } IACA_END
}
