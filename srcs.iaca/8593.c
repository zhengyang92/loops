#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef FilterSignal;
typedef __int32_t int32_t;

int
fn (int32_t * samples, int32_t subbands[2], int i, int shift,
    FilterSignal * signal, const int32_t (*coeffs)[16])
{
  for (i = 0; i < 2; i++)
    {
      aptx_qmf_filter_signal_push (&signal[i], subbands[1 - i]);
      samples[i] = aptx_qmf_convolution (&signal[i], coeffs[i], shift);
    }
}
