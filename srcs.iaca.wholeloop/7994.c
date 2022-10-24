#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int lp_half_order, const double *lsp, double pa[11], double *qa,
    int j, float *lp, int lp_order)
{
  IACA_START for (i = 1, j = lp_order - 1; i < lp_half_order; i++, j--)
    {
      double paf = pa[i] * (1 + lsp[lp_order - 1]);
      double qaf = (qa[i] - qa[i - 2]) * (1 - lsp[lp_order - 1]);
      lp[i - 1] = (paf + qaf) * 0.5;
      lp[j - 1] = (paf - qaf) * 0.5;
}IACA_END}
