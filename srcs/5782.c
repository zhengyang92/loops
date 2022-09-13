#include <stdint.h>
#include <stdio.h>






int
fn (int int_part, const float *in0, int i, float *out, int k,
    const float upsample_fir[4][24])
{
  int frac_part = 0;
  for (k = 1; k < 5; k++)
    {
      out[i] =
	avpriv_scalarproduct_float_c (in0 + int_part,
				      upsample_fir[4 - frac_part], (2 * 12));
      int_part++;
      frac_part--;
      i++;
    }
}
