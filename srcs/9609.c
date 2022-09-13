#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int b1, int i, int d1, int c1, int16_t tmp[16], int16_t * dc, int a1)
{
  for (i = 0; i < 4; i++)
    {
      a1 = (dc[i * 4 + 0] + dc[i * 4 + 2]) * 23170;
      b1 = (dc[i * 4 + 0] - dc[i * 4 + 2]) * 23170;
      c1 = dc[i * 4 + 1] * 12540 - dc[i * 4 + 3] * 30274;
      d1 = dc[i * 4 + 1] * 30274 + dc[i * 4 + 3] * 12540;
      tmp[i * 4 + 0] = (a1 + d1) >> 14;
      tmp[i * 4 + 3] = (a1 - d1) >> 14;
      tmp[i * 4 + 1] = (b1 + c1) >> 14;
      tmp[i * 4 + 2] = (b1 - c1) >> 14;
    }
}
