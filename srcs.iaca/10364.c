#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *input, float largest, int n, int stride)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      if (input[i * stride] > largest)
	largest = input[i * stride];
     } IACA_END
}
