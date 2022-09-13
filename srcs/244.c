#include <stdint.h>
#include <stdio.h>






int
fn (float *h, int i, float beta, float Fc, int m, float sum, float mult1,
    float mult)
{
  for (i = 0; i <= m / 2; i++)
    {
      float z = i - .5f * m, x = z * 3.14159265358979323846, y = z * mult1;
      h[i] = x ? sinf (Fc * x) / x : Fc;
      sum += h[i] *= bessel_I_0 (beta * sqrtf (1.f - y * y)) * mult;
      if (m - i != i)
	{
	  h[m - i] = h[i];
	  sum += h[i];
	}
    }
}
