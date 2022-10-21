#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int n2, const int n, int i, float *in)
{
  for (i = 0; i < n2; i += 2)
     { IACA_START
      float temp;
      temp = in[i];
      in[i] = -in[n - 1 - i];
      in[n - 1 - i] = temp;
      temp = -in[i + 1];
      in[i + 1] = in[n - 2 - i];
      in[n - 2 - i] = temp;
} IACA_END }
