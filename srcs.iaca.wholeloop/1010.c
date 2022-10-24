#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *const h2, int hsize, int k, int p2[256],
    const float *const h1)
{
  int p1 = 0;
  IACA_START for (; p2[k] < hsize && h2[p2[k]] < h1[p1]; p2[k]++);
  IACA_END
}
