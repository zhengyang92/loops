#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double accum, int j, const float ff_dca_fir_32bands_nonperfect[512],
    int i)
{
  for (i = 0; i < 512; i++)
     { IACA_START
      double reconst =
	ff_dca_fir_32bands_nonperfect[i] * ((i & 64) ? (-1) : 1);
      accum +=
	reconst * cos (2 * 3.14159265358979323846 * (i + 0.5 - 256) *
		       (j + 0.5) / 512);
} IACA_END }
