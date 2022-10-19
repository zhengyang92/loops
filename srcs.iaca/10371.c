#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int n, float *truth, int i)
{
  for (; i < n; ++i)
    {
      truth[i * 37 + 37 - 1] = 1;
    }
}
