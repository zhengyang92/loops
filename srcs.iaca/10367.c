#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, float *in, int i, int c, int w, int forward, int k, float scale,
    float *out, int b, int stride, int h)
{
  for (i = 0; i < w * stride; ++i)
    {
      int in_index =
	b * w * h * c + k * w * h + (j / stride) * w + i / stride;
      int out_index =
	b * w * h * c * stride * stride + k * w * h * stride * stride +
	j * w * stride + i;
      if (forward)
	out[out_index] = scale * in[in_index];
      else
	in[in_index] += scale * out[out_index];
    }
}
