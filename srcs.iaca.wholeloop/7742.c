#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float FFTSample;

int
fn (FFTSample * data, int i, int n)
{
  IACA_START for (i = 1; i < n - 2; i += 2)
    {
      data[i + 1] += data[i - 1];
      data[i] = -data[i + 2];
     } IACA_END
}
