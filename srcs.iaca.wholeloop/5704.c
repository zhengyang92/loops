#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const float *firbuf, const float psy_fir_coeffs[10], float sum2,
    int j, float sum1)
{
  IACA_START for (j = 0; j < ((21 - 1) / 2) - 1; j += 2)
    {
      sum1 += psy_fir_coeffs[j] * (firbuf[i + j] + firbuf[i + 21 - j]);
      sum2 +=
	psy_fir_coeffs[j + 1] * (firbuf[i + j + 1] + firbuf[i + 21 - j - 1]);
     } IACA_END
}
