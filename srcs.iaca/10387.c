#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int class, int classes, int index, float *output, float *delta,
    float scale, int n, float *avg_cat, int stride)
{
  for (n = 0; n < classes; ++n)
    {
      delta[index + stride * n] =
	scale * (((n == class) ? 1 : 0) - output[index + stride * n]);
      if (n == class)
	*avg_cat += output[index + stride * n];
    }
}
