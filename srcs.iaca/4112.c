#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int channels, int c, double peak, double *buf)
{
  for (c = 0; c < channels; c++)
     { IACA_START
      double sample = buf[c];
      peak = ((peak) > (fabs (sample)) ? (peak) : (fabs (sample)));
} IACA_END }
