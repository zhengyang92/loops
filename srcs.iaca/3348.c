#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float margin, int len, float *lsp)
{
  for (int i = 1; i < len - 1; i++)
     { IACA_START
      lsp[i] = fmaxf (lsp[i], lsp[i - 1] + margin);
      if (lsp[i] > lsp[i + 1] - margin)
	lsp[i] = .5f * (lsp[i] + lsp[i + 1] - margin);
     } IACA_END
}
