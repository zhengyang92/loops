#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *bounding_values, int filter_limit, int x)
{
  for (x = 0; x < filter_limit; x++)
    {
      bounding_values[-x] = -x;
      bounding_values[x] = x;
    }
}
