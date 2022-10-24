#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int cmap[256], int i, unsigned long hist[256])
{
  IACA_START for (i = 0; i < 256; ++i)
    {
      hist[i] = 0;
      cmap[i] = 0;
     } IACA_END
}
