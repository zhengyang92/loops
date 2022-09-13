#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float *x, int c, int w, int forward, int k, int out_c,
    float *out, int b, int stride, int h)
{
  for (i = 0; i < w; ++i)
    {
      int in_index = i + w * (j + h * (k + c * b));
      int c2 = k % out_c;
      int offset = k / out_c;
      int w2 = i * stride + offset % stride;
      int h2 = j * stride + offset / stride;
      int out_index = w2 + w * stride * (h2 + h * stride * (c2 + out_c * b));
      if (forward)
	out[out_index] = x[in_index];
      else
	out[in_index] = x[out_index];
    }
}
