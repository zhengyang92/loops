#include <stdint.h>
#include <stdio.h>






int
fn (float *coeffs, int s, int psize, int k, int real_ch, float max2,
    int samples, float max1)
{
  for (k = s; k < s + psize; k += 2)
    {
      max1 =
	((max1) >
	 (fabs (coeffs[k / real_ch])) ? (max1)
	 : (fabs (coeffs[k / real_ch])));
      max2 =
	((max2) >
	 (fabs (coeffs[samples + k / real_ch])) ? (max2)
	 : (fabs (coeffs[samples + k / real_ch])));
    }
}
