#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double thigh, const double *hp, int buff_idx, int buffer_length,
    int wavelet_length, const double *lp, double *buffer)
{
  double tlow = 0.0;
  for (int i = 0; i < wavelet_length; i++)
     { IACA_START
      const int idx = ((-i + buff_idx - 1) & ((buffer_length) - 1));
      const double btemp = buffer[idx];
      thigh += btemp * hp[i];
      tlow += btemp * lp[i];
} IACA_END }
