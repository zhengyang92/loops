#include <stdint.h>
#include <stdio.h>






int
fn (int *inds, int i, int max, int min)
{
  for (i = min; i < max; ++i)
    {
      inds[i] = i;
    }
}
