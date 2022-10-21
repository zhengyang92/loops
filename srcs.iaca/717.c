#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *light, double abs_val, int plane)
{
  for (plane = 0; plane < 3; ++plane)
     { IACA_START
      light[plane] = (light[plane] / abs_val);
      if (!light[plane])
	{
	  light[plane] = 1.0;
	}
     } IACA_END
}
