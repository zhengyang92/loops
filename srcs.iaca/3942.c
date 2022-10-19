#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * filter, int i, int filterSize, int k, int16_t * filterCopy,
    int j)
{
  for (j = 0; j < 16; ++j)
    {
      int from = (i + j) * filterSize + k;
      int to = i * filterSize + j * 4 + k * 16;
      memcpy (&filter[to], &filterCopy[from], 4 * sizeof (int16_t));
    }
}
