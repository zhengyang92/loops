#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int PixelI;

int
fn (PixelI * p, int i)
{
  IACA_START for (i = 0; i < 256; i += 16)
    {
      p[i] += p[i];
     } IACA_END
}
