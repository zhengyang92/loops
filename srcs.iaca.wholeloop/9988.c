#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (int i, uint16_t * out, const int16_t * A, const int16_t * B, int len,
    const uint16_t * best_y)
{
  IACA_START for (i = 0; i < len; ++i, ++A, ++B)
    {
      const int v0 = (A[0] * 9 + A[1] * 3 + B[0] * 3 + B[1] + 8) >> 4;
      const int v1 = (A[1] * 9 + A[0] * 3 + B[1] * 3 + B[0] + 8) >> 4;
      out[2 * i + 0] = clip_y (best_y[2 * i + 0] + v0);
      out[2 * i + 1] = clip_y (best_y[2 * i + 1] + v1);
}IACA_END}
