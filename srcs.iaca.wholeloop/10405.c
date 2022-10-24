#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *out, int j, int inputs)
{
  IACA_START for (j = 0; j < inputs; ++j)
    {
      if (out[j] < .0001)
	out[j] = 0;
     } IACA_END
}
