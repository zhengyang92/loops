#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int i, float *samples)
{
  IACA_START for (i = 511; i > 0; i--)
    {
      samples[2 * i] = samples[2 * i + 1] = samples[i];
     } IACA_END
}
