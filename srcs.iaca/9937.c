#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int tmp[16], int i, const uint16_t * w)
{
  int sum = 0;
  for (i = 0; i < 4; ++i, ++w)
    {
      const int a0 = tmp[0 + i] + tmp[8 + i];
      const int a1 = tmp[4 + i] + tmp[12 + i];
      const int a2 = tmp[4 + i] - tmp[12 + i];
      const int a3 = tmp[0 + i] - tmp[8 + i];
      const int b0 = a0 + a1;
      const int b1 = a3 + a2;
      const int b2 = a3 - a2;
      const int b3 = a0 - a1;
      sum += w[0] * abs (b0);
      sum += w[4] * abs (b1);
      sum += w[8] * abs (b2);
      sum += w[12] * abs (b3);
}}
