#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *lpc, int i)
{
  double bandwidth_expansion_coeff = 0.9883;
  for (i = 0; i < 10; i++)
    {
      lpc[i] *= bandwidth_expansion_coeff;
      bandwidth_expansion_coeff *= 0.9883;
    }
}
