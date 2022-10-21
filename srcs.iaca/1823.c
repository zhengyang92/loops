#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *samples, int i, const float ff_dca_quant_amp[57], uint8_t * g2_scf,
    uint8_t * hr_scf)
{
  for (i = 0; i < 128 / 2; i++, samples += 2)
     { IACA_START
      unsigned int scf = hr_scf[i / 8] - g2_scf[i];
      if (scf > 56)
	scf = 56;
      samples[0] *= ff_dca_quant_amp[scf];
      samples[1] *= ff_dca_quant_amp[scf];
     } IACA_END
}
