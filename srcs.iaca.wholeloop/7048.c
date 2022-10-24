#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int t1, int i, int16_t * dc, int16_t (*block)[4][16], int t0, int t3,
    int t2)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      t0 = dc[i * 4 + 0] + dc[i * 4 + 3] + 3;
      t1 = dc[i * 4 + 1] + dc[i * 4 + 2];
      t2 = dc[i * 4 + 1] - dc[i * 4 + 2];
      t3 = dc[i * 4 + 0] - dc[i * 4 + 3] + 3;
      dc[i * 4 + 0] = 0;
      dc[i * 4 + 1] = 0;
      dc[i * 4 + 2] = 0;
      dc[i * 4 + 3] = 0;
      block[i][0][0] = (t0 + t1) >> 3;
      block[i][1][0] = (t3 + t2) >> 3;
      block[i][2][0] = (t0 - t1) >> 3;
      block[i][3][0] = (t3 - t2) >> 3;
     } IACA_END
}
