#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float sigma, float *buff, const int block, const int method,
    const float limit)
{
  for (int j = 0; j < block; j++)
    {
      float factor, power, re, im;
      re = buff[j * 2];
      im = buff[j * 2 + 1];
      power = re * re + im * im;
      switch (method)
	{
	case 0:
	  factor = fmaxf (limit, (power - sigma) / (power + 1e-15f));
	  break;
	case 1:
	  factor = power < sigma ? limit : 1.f;
	  break;
	}
      buff[j * 2] *= factor;
      buff[j * 2 + 1] *= factor;
    }
}
