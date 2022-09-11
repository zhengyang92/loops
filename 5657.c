#include <stdint.h>
#include <stdio.h>






int
fn (int *quants, const int dim, int off, int j, const int range)
{
  int curidx = 0;
  for (j = 0; j < dim; j++)
    {
      curidx *= range;
      curidx += quants[j] + off;
    }
}
