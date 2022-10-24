#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int16_t (*src)[8], const uint8_t * cm,
    uint8_t * dst)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      const int a0 = 3 * src[1][i] - (src[7][i] << 1);
      const int a1 = 3 * src[3][i] + (src[5][i] << 1);
      const int a2 = (src[3][i] << 1) - 3 * src[5][i];
      const int a3 = (src[1][i] << 1) + 3 * src[7][i];
      const int b4 = ((a0 + a1 + a3) << 1) + a1;
      const int b5 = ((a0 - a1 + a2) << 1) + a0;
      const int b6 = ((a3 - a2 - a1) << 1) + a3;
      const int b7 = ((a0 - a2 - a3) << 1) - a2;
      const int a7 = (src[2][i] << 2) - 10 * src[6][i];
      const int a6 = (src[6][i] << 2) + 10 * src[2][i];
      const int a5 = (src[0][i] - src[4][i]) << 3;
      const int a4 = (src[0][i] + src[4][i]) << 3;
      const int b0 = a4 + a6;
      const int b1 = a5 + a7;
      const int b2 = a5 - a7;
      const int b3 = a4 - a6;
      dst[i + 0 * stride] = cm[dst[i + 0 * stride] + ((b0 + b4) >> 7)];
      dst[i + 1 * stride] = cm[dst[i + 1 * stride] + ((b1 + b5) >> 7)];
      dst[i + 2 * stride] = cm[dst[i + 2 * stride] + ((b2 + b6) >> 7)];
      dst[i + 3 * stride] = cm[dst[i + 3 * stride] + ((b3 + b7) >> 7)];
      dst[i + 4 * stride] = cm[dst[i + 4 * stride] + ((b3 - b7) >> 7)];
      dst[i + 5 * stride] = cm[dst[i + 5 * stride] + ((b2 - b6) >> 7)];
      dst[i + 6 * stride] = cm[dst[i + 6 * stride] + ((b1 - b5) >> 7)];
      dst[i + 7 * stride] = cm[dst[i + 7 * stride] + ((b0 - b4) >> 7)];
}IACA_END}
