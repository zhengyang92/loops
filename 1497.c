#include <stdint.h>
#include <stdio.h>






int
fn (float *buf, int i, const int start, float s0, const float *new, int j)
{
  float s1 = 0.0f;
  for (j = start; j < 2048; j++)
    {
      const int idx = j - i + 1024;
      s0 += new[j] * buf[idx];
      s1 += buf[idx] * buf[idx];
}}
