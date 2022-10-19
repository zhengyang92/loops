#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *inds, int i, int min, int max)
{
  for (i = min; i < max; ++i)
    {
      inds[i] = i;
    }
}
