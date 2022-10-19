#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float mem, float *out, float alpha, int size, const float *in,
    float gain_scale_factor)
{
  for (i = 0; i < size; i++)
    {
      mem = alpha * mem + gain_scale_factor;
      out[i] = in[i] * mem;
    }
}
