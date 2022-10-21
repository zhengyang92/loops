#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef FilterSignal;

int
fn (int32_t * samples, int32_t subbands[2], int i, int shift,
    FilterSignal * signal, const int32_t (*coeffs)[16])
{
  for (i = 0; i < 2; i++)
     { IACA_START
      aptx_qmf_filter_signal_push (&signal[i], samples[2 - 1 - i]);
      subbands[i] = aptx_qmf_convolution (&signal[i], coeffs[i], shift);
     } IACA_END
}
