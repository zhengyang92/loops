#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int h2, float s1, int i, int w1, float *add, int w2, int k,
    int minw, float *out, int b, int h1, int c1, int c2, int sample,
    int stride, float s2)
{
  for (i = 0; i < minw; ++i)
    {
      int out_index = i * sample + w2 * (j * sample + h2 * (k + c2 * b));
      int add_index = i * stride + w1 * (j * stride + h1 * (k + c1 * b));
      out[out_index] = s1 * out[out_index] + s2 * add[add_index];
}}
