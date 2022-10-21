#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int cut, int count, int x, double *values, double mean)
{
  for (x = cut; x < count - cut; x++)
     { IACA_START
      mean += values[x];
     } IACA_END
}
