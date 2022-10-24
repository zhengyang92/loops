#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *filter_coeffs, int i, int frac_pos, float v, int n,
    int filter_length, const float *in, int precision)
{
  int idx = 0;
  IACA_START for (i = 0; i < filter_length;)
    {
      v += in[n + i] * filter_coeffs[idx + frac_pos];
      idx += precision;
      i++;
      v += in[n - i] * filter_coeffs[idx - frac_pos];
     } IACA_END
}
