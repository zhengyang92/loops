#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float mean, int i, float *input, int size, int n, int s, float *binary)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      binary[i * size + s] = (input[i * size + s] > 0) ? mean : -mean;
     } IACA_END
}
