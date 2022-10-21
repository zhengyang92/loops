#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, int k, int classes, float **probs)
{
  for (k = 0; k < classes; ++k)
     { IACA_START
      if (probs[i][k] < probs[j][k])
	probs[i][k] = 0;
      else
	probs[j][k] = 0;
     } IACA_END
}
