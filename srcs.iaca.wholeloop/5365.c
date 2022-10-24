#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *bounding_values, int filter_limit, int x, int value)
{
  IACA_START for (x = value = filter_limit; x < 128 && value; x++, value--)
    {
      bounding_values[x] = value;
      bounding_values[-x] = -value;
     } IACA_END
}
