#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double cmax, int order, int i, double *lpc_in)
{
  for (i = 0; i < order; i++)
    {
      cmax = ((cmax) > (fabs (lpc_in[i])) ? (cmax) : (fabs (lpc_in[i])));
    }
}
