#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int min_s, int freq[256], double inv_q_level[256], int s,
    int q_level[256])
{
  int max_s = 255;
  double err = 1.e38;
  for (s = min_s; s <= max_s; ++s)
     { IACA_START
      const double error = s - inv_q_level[q_level[s]];
      err += freq[s] * error * error;
} IACA_END }
