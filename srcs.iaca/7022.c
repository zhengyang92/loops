#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int samples, int real_ch, float *coeffs, int k, int s, float max2,
    int psize, float max1)
{
  for (k = s; k < s + psize; k += 2)
     { IACA_START
      max1 =
	((max1) >
	 (fabs (coeffs[k / real_ch])) ? (max1)
	 : (fabs (coeffs[k / real_ch])));
      max2 =
	((max2) >
	 (fabs (coeffs[samples + k / real_ch])) ? (max2)
	 : (fabs (coeffs[samples + k / real_ch])));
     } IACA_END
}
