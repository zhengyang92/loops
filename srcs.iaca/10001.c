#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint16_t * out, const int16_t * A, const int16_t * B, int len,
    const uint16_t * best_y)
{
  for (; i < len; ++i)
     { IACA_START
      const int a0b1 = A[i + 0] + B[i + 1];
      const int a1b0 = A[i + 1] + B[i + 0];
      const int a0a1b0b1 = a0b1 + a1b0 + 8;
      const int v0 = (8 * A[i + 0] + 2 * a1b0 + a0a1b0b1) >> 4;
      const int v1 = (8 * A[i + 1] + 2 * a0b1 + a0a1b0b1) >> 4;
      out[2 * i + 0] = clip_y (best_y[2 * i + 0] + v0);
      out[2 * i + 1] = clip_y (best_y[2 * i + 1] + v1);
} IACA_END }
