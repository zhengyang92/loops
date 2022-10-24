#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *light, double abs_val, int plane)
{
  IACA_START for (plane = 0; plane < 3; ++plane)
    {
      light[plane] = (light[plane] / abs_val);
      if (!light[plane])
	{
	  light[plane] = 1.0;
	}
     } IACA_END
}
