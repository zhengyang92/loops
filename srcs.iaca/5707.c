#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (float base, int present, float prod, int num_bands, int previous, int k,
    int16_t * bands)
{
  for (k = 0; k < num_bands - 1; k++)
    {
      prod *= base;
      present = lrintf (prod);
      bands[k] = present - previous;
      previous = present;
    }
}
