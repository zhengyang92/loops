#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int b1, int i, int d1, int c1, int16_t tmp[16], int16_t * dc,
    int16_t (*block)[4][16], int a1)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      a1 = (tmp[i + 0] + tmp[i + 8]) * 23170;
      b1 = (tmp[i + 0] - tmp[i + 8]) * 23170;
      c1 = tmp[i + 4] * 12540 - tmp[i + 12] * 30274;
      d1 = tmp[i + 4] * 30274 + tmp[i + 12] * 12540;
      dc[i * 4 + 0] = 0;
      dc[i * 4 + 1] = 0;
      dc[i * 4 + 2] = 0;
      dc[i * 4 + 3] = 0;
      block[0][i][0] = (a1 + d1 + 0x20000) >> 18;
      block[3][i][0] = (a1 - d1 + 0x20000) >> 18;
      block[1][i][0] = (b1 + c1 + 0x20000) >> 18;
      block[2][i][0] = (b1 - c1 + 0x20000) >> 18;
     } IACA_END
}
