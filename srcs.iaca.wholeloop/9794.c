#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;
typedef unsigned short uint16;

int
fn (tmsize_t n, tmsize_t i, uint16 ** tf)
{
  IACA_START for (i = 1; i < n; i++)
    {
      double t = (double) i / ((double) n - 1.);
      tf[0][i] = (uint16) floor (65535. * pow (t, 2.2) + .5);
}IACA_END}
