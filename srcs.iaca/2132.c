#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t delayed_signal[7][41],
    const int16_t ff_g729_interp_filt_short[16], int subframe_size,
    int16_t best_delay_int, int k, int16_t sig_scaled[192])
{
  for (k = 0; k < 7; k++)
     { IACA_START
      ff_acelp_interpolate (&delayed_signal[k][0],
			    &sig_scaled[(143 + 8 + 1) - best_delay_int],
			    ff_g729_interp_filt_short, 7 + 1, 8 - k - 1, 2,
			    subframe_size + 1);
     } IACA_END
}
