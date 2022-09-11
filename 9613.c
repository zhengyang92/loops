#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int t1, int i, int16_t * dc, int t0, int t3, int t2)
{
  for (i = 0; i < 4; i++)
    {
      t0 = dc[0 * 4 + i] + dc[3 * 4 + i];
      t1 = dc[1 * 4 + i] + dc[2 * 4 + i];
      t2 = dc[1 * 4 + i] - dc[2 * 4 + i];
      t3 = dc[0 * 4 + i] - dc[3 * 4 + i];
      dc[0 * 4 + i] = t0 + t1;
      dc[1 * 4 + i] = t3 + t2;
      dc[2 * 4 + i] = t0 - t1;
      dc[3 * 4 + i] = t3 - t2;
    }
}
