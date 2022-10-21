#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, float two_cos_w, int order, float *lsp)
{
  float q = 0.5f;
  float p = 0.5f;
  for (j = 0; j + 1 < order; j += 2)
     { IACA_START
      q *= lsp[j] - two_cos_w;
      p *= lsp[j + 1] - two_cos_w;
     } IACA_END
}
