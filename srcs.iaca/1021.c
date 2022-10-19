#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float t, float *coeffs)
{
  float sum = 0.f;
  for (int i = 0; i < 4; i++)
    {
      const float x = 3.14159265358979323846 * (t - i + 1);
      if (x == 0.f)
	{
	  coeffs[i] = 1.f;
	}
      else
	{
	  coeffs[i] = sinf (x) * sinf (x / 2.f) / (x * x / 2.f);
	}
      sum += coeffs[i];
    }
}
