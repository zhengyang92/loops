#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (int x, size_t hsize, float *histogram)
{
  for (x = 0; x < hsize - 1; x++)
     { IACA_START
      histogram[x + 1] += histogram[x];
      histogram[x] /= hsize;
     } IACA_END
}
