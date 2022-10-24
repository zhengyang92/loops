#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *out, float v2, int size, float step)
{
  IACA_START for (i = 0; i < size; i++)
    {
      v2 += step;
      out[i] = v2;
     } IACA_END
}
