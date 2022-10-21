#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *out, int j, int inputs)
{
  for (j = 0; j < inputs; ++j)
     { IACA_START
      if (out[j] < .0001)
	out[j] = 0;
     } IACA_END
}
