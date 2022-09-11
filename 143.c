#include <stdint.h>
#include <stdio.h>






int
fn (int idx, float norm, const float *const spectral, int size)
{
  float sum = 0.f;
  for (int n = 0; n < size; n++)
    {
      sum += spectral[n];
      if (sum >= norm)
	{
	  idx = n;
	  break;
	}
    }
}
