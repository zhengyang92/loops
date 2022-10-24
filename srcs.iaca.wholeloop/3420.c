#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *lsp, int j, int order, float two_cos_w)
{
  float q = 0.5f;
  float p = 0.5f;
  IACA_START for (j = 0; j + 1 < order; j += 2 * 2)
    {
      q *= lsp[j] - two_cos_w;
      p *= lsp[j + 1] - two_cos_w;
      q *= lsp[j + 2] - two_cos_w;
      p *= lsp[j + 3] - two_cos_w;
     } IACA_END
}
