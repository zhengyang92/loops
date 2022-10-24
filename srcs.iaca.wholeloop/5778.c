#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *samples, int i)
{
  IACA_START for (i = 0; i < 40; i++)
    if (fabsf (samples[i]) > 32768.0)
      {
	return 1;
      }
  IACA_END
}
