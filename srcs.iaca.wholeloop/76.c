#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int channels, int c, double *buf, double peak)
{
  IACA_START for (c = 0; c < channels; c++)
    {
      double sample = buf[c];
      peak = ((peak) > (fabs (sample)) ? (peak) : (fabs (sample)));
}IACA_END}
