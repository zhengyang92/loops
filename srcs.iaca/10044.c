#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const double scale, int v, uint32_t kLinearToGammaTabS[34])
{
  const double a = 0.09929682680944;
  const double thresh = 0.018053968510807;
  for (v = 0; v <= (1 << (12 - 7)); ++v)
    {
      const double g = scale * v;
      double value;
      if (g <= thresh)
	{
	  value = 4.5 * g;
	}
      else
	{
	  value = (1. + a) * pow (g, 1. / (1. / 0.45)) - a;
	}
      kLinearToGammaTabS[v] =
	(uint32_t) (((256 << 2) - 1) * value) + (1 << 14 >> 1);
    }
}
