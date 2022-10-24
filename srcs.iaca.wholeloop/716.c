#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *light, int plane)
{
  IACA_START for (plane = 0; plane < 3; ++plane)
    {
      light[plane] = 1.0;
     } IACA_END
}
