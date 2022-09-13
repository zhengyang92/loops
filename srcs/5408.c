#include <stdint.h>
#include <stdio.h>




typedef float WMACoef;

int
fn (float *coefs, int i, int n, WMACoef * coefs1, float *exponents,
    float mult)
{
  for (i = 0; i < n; i++)
    {
      double t = *coefs++ / (exponents[i] * mult);
      if (t < -32768 || t > 32767)
	return -1;
      coefs1[i] = lrint (t);
    }
}
