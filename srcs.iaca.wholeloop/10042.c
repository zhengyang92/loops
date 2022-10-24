#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int kLinearToGammaTab[33], int v, const double scale)
{
  IACA_START for (v = 0; v <= (1 << (12 - 7)); ++v)
    {
      kLinearToGammaTab[v] = (int) (255. * pow (scale * v, 1. / 0.80) + .5);
}IACA_END}
