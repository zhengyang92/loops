#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int b1, int d1, int i, int16_t * block, int c1, int16_t tmp[16], int a1)
{
  for (i = 0; i < 4; i++)
    {
      a1 = (block[i * 4 + 0] + block[i * 4 + 2]) * 23170;
      b1 = (block[i * 4 + 0] - block[i * 4 + 2]) * 23170;
      c1 = block[i * 4 + 1] * 12540 - block[i * 4 + 3] * 30274;
      d1 = block[i * 4 + 1] * 30274 + block[i * 4 + 3] * 12540;
      block[i * 4 + 0] = 0;
      block[i * 4 + 1] = 0;
      block[i * 4 + 2] = 0;
      block[i * 4 + 3] = 0;
      tmp[i * 4 + 0] = (a1 + d1) >> 14;
      tmp[i * 4 + 3] = (a1 - d1) >> 14;
      tmp[i * 4 + 1] = (b1 + c1) >> 14;
      tmp[i * 4 + 2] = (b1 - c1) >> 14;
    }
}
