#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *light, int plane)
{
  for (plane = 0; plane < 3; ++plane)
     { IACA_START
      light[plane] = 1.0;
     } IACA_END
}
