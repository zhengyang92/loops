#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double thigh, const double *hp, int buff_idx, int buffer_length,
    int wavelet_length, const double *lp, double *buffer)
{
  double tlow = 0.0;
  IACA_START for (int j = 0; j < wavelet_length; j++)
    {
      const int idx = ((-j + buff_idx - 1) & ((buffer_length) - 1));
      const double btemp = buffer[idx];
      thigh += btemp * hp[j];
      tlow += btemp * lp[j];
}IACA_END}
