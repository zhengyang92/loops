#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int channels, double max, double *buf, int c)
{
  IACA_START for (c = 0; c < channels; c++)
    {
      max = fabs (buf[c]) > max ? fabs (buf[c]) : max;
     } IACA_END
}
