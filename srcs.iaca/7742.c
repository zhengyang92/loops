#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float FFTSample;

int
fn (FFTSample * data, int i, int n)
{
  for (i = 1; i < n - 2; i += 2)
     { IACA_START
      data[i + 1] += data[i - 1];
      data[i] = -data[i + 2];
     } IACA_END
}
