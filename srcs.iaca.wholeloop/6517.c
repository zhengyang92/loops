#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int16_t FFTSample;

int
fn (FFTSample * output, int n, int k, int n4, int n2)
{
  IACA_START for (k = 0; k < n4; k++)
    {
      output[k] = -output[n2 - k - 1];
      output[n - k - 1] = output[n2 + k];
     } IACA_END
}
