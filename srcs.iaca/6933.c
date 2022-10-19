#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *lsp, float min_dist, float min_dist2, int order)
{
  for (i = 1; i < order; i++)
    if (lsp[i] - lsp[i - 1] < min_dist)
      {
	float avg = (lsp[i] + lsp[i - 1]) * 0.5;
	lsp[i - 1] = avg - min_dist2;
	lsp[i] = avg + min_dist2;
      }
}
