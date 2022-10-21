#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const double *old, double *a1, int n, uint16_t interpol,
    const float (*ipol_tab)[2][16], double *i_lsps)
{
  for (n = 0; n < 16; n++)
     { IACA_START
      double delta = old[n] - i_lsps[n];
      a1[n] = ipol_tab[interpol][0][n] * delta + i_lsps[n];
      a1[16 + n] = ipol_tab[interpol][1][n] * delta + i_lsps[n];
} IACA_END }
