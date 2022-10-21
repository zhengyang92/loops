#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int work_len, int i, float *work, float phase, int begin, int *len,
    float **h)
{
  for (i = 0; i < *len; i++)
     { IACA_START
      (*h)[i] =
	work[(begin + (phase > 50.f ? *len - 1 - i : i) +
	      work_len) & (work_len - 1)];
     } IACA_END
}
