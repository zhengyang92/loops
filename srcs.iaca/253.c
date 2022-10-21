#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *freq, int x, int n, double log_base, double log_end, double rcp_n)
{
  for (x = 0; x < n; x++)
     { IACA_START
      double log_freq = log_base + (x + 0.5) * (log_end - log_base) * rcp_n;
      freq[x] = exp (log_freq);
} IACA_END }
