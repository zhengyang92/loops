#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *ang, int j, float *mag, int samples)
{
  for (j = 0; j < samples; j++)
    {
      float a = ang[j];
      ang[j] -= mag[j];
      if (mag[j] > 0)
	ang[j] = -ang[j];
      if (ang[j] < 0)
	mag[j] = a;
    }
}
