#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *buf, const int n, int i)
{
  for (i = 0; i < n; i += 2)
    {
      buf[i] = -buf[i];
    }
}
