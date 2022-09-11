#include <stdint.h>
#include <stdio.h>






int
fn (double scale, int order, int i, double *lpc_in)
{
  for (i = 0; i < order; i++)
    {
      lpc_in[i] *= scale;
    }
}
