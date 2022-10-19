#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *avg, int n, int i, int els)
{
  for (i = 0; i < els; ++i)
    {
      avg[i] /= n;
    }
}
