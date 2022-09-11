#include <stdint.h>
#include <stdio.h>






int
fn (int class, int index, float *output, float *delta, int n, int stride,
    float *avg_cat, int classes)
{
  for (n = 0; n < classes; ++n)
    {
      delta[index + stride * n] =
	((n == class) ? 1 : 0) - output[index + stride * n];
      if (n == class && avg_cat)
	*avg_cat += output[index + stride * n];
    }
}
