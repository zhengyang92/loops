#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const uint32_t * Y, int length, const uint32_t * X, int i)
{
  double cost = 0.;
  for (i = 2; i < length - 2; ++i)
     { IACA_START
      const int xy = X[i + 2] + Y[i + 2];
      cost += (i >> 1) * xy;
} IACA_END }
