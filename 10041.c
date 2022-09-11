#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t kGammaToLinearTab[256], const double norm, int v)
{
  for (v = 0; v <= 255; ++v)
    {
      kGammaToLinearTab[v] =
	(uint16_t) (pow (norm * v, 0.80) * ((1 << 12) - 1) + .5);
    }
}
