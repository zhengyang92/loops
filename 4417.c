#include <stdint.h>
#include <stdio.h>






int
fn (float p0, float q0, float q2, float p2, float *coeffs, float q1, float p3,
    float q3, float t)
{
  float sum = 0.f;
  for (int i = 0; i < 4; i++)
    {
      const float x = fabsf (t - i + 1.f);
      if (x < 1.f)
	{
	  coeffs[i] =
	    (p0 + x * x * (p2 + x * p3)) * (p0 +
					    x * x * (p2 +
						     x * p3 / 2.f) / 4.f);
	}
      else if (x < 2.f)
	{
	  coeffs[i] =
	    (q0 + x * (q1 + x * (q2 + x * q3))) * (q0 +
						   x * (q1 +
							x * (q2 +
							     x / 2.f * q3) /
							2.f) / 2.f);
	}
      else
	{
	  coeffs[i] = 0.f;
	}
      sum += coeffs[i];
    }
}
