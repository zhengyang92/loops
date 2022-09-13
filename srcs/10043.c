#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const double final_scale, uint32_t kGammaToLinearTabS[1024],
    const double norm, int v)
{
  const double a = 0.09929682680944;
  const double thresh = 0.018053968510807;
  for (v = 0; v <= ((256 << 2) - 1); ++v)
    {
      const double g = norm * v;
      double value;
      if (g <= thresh * 4.5)
	{
	  value = g / 4.5;
	}
      else
	{
	  const double a_rec = 1. / (1. + a);
	  value = pow (a_rec * (g + a), (1. / 0.45));
	} kGammaToLinearTabS[v] = (uint32_t) (value * final_scale + .5);
}}
