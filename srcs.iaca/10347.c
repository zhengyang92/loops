#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *a, float *b, float *c, int n, float *s)
{
  for (i = 0; i < n; ++i)
    {
      c[i] = s[i] * a[i] + (1 - s[i]) * (b ? b[i] : 0);
    }
}
