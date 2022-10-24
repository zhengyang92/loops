#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float margin, int len, float *lsp)
{
  IACA_START for (int i = 1; i < len - 1; i++)
    {
      lsp[i] = fmaxf (lsp[i], lsp[i - 1] + margin);
      if (lsp[i] > lsp[i + 1] - margin)
	lsp[i] = .5f * (lsp[i] + lsp[i + 1] - margin);
     } IACA_END
}
