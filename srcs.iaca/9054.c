#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int n, const int n2, float *in)
{
  for (i = 0; i < n2; i += 2)
    {
      float temp;
      temp = in[i];
      in[i] = -in[n - 1 - i];
      in[n - 1 - i] = temp;
      temp = -in[i + 1];
      in[i + 1] = in[n - 2 - i];
      in[n - 2 - i] = temp;
}}
