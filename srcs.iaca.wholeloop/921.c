#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (int x, size_t hsize, float *histogram)
{
  IACA_START for (x = 0; x < hsize - 1; x++)
    {
      histogram[x + 1] += histogram[x];
      histogram[x] /= hsize;
     } IACA_END
}
