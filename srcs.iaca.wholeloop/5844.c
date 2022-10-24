#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t (*src)[8], int i)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      const int a0 = 3 * src[i][1] - (src[i][7] << 1);
      const int a1 = 3 * src[i][3] + (src[i][5] << 1);
      const int a2 = (src[i][3] << 1) - 3 * src[i][5];
      const int a3 = (src[i][1] << 1) + 3 * src[i][7];
      const int b4 = ((a0 + a1 + a3) << 1) + a1;
      const int b5 = ((a0 - a1 + a2) << 1) + a0;
      const int b6 = ((a3 - a2 - a1) << 1) + a3;
      const int b7 = ((a0 - a2 - a3) << 1) - a2;
      const int a7 = (src[i][2] << 2) - 10 * src[i][6];
      const int a6 = (src[i][6] << 2) + 10 * src[i][2];
      const int a5 = ((src[i][0] - src[i][4]) << 3) + 4;
      const int a4 = ((src[i][0] + src[i][4]) << 3) + 4;
      const int b0 = a4 + a6;
      const int b1 = a5 + a7;
      const int b2 = a5 - a7;
      const int b3 = a4 - a6;
      src[i][0] = (b0 + b4) >> 3;
      src[i][1] = (b1 + b5) >> 3;
      src[i][2] = (b2 + b6) >> 3;
      src[i][3] = (b3 + b7) >> 3;
      src[i][4] = (b3 - b7) >> 3;
      src[i][5] = (b2 - b6) >> 3;
      src[i][6] = (b1 - b5) >> 3;
      src[i][7] = (b0 - b4) >> 3;
}IACA_END}
