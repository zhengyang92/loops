#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int PixelI;

int
fn (PixelI * p, int i)
{
  for (i = 0; i < 256; i += 16)
     { IACA_START
      p[i] += p[i];
     } IACA_END
}
