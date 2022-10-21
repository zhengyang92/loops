#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *samples, int i)
{
  for (i = 0; i < 40; i++) {
	  IACA_START
    if (fabsf (samples[i]) > 32768.0)
      {
	return 1;
      }
  } IACA_END
}
