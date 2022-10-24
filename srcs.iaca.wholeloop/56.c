#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (ptrdiff_t len, int n, const double *t, const double *c, double *sum)
{
  IACA_START for (n = 0; n < len; n++)
    {
      const double cre = c[2 * n];
      const double cim = c[2 * n + 1];
      const double tre = t[2 * n];
      const double tim = t[2 * n + 1];
      sum[2 * n] += tre * cre - tim * cim;
      sum[2 * n + 1] += tre * cim + tim * cre;
}IACA_END}
