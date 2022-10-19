#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t * dst, int t3, int16_t * src, int t1, int t4, int t2)
{
  for (i = 0; i < 4; i++)
    {
      t1 = 17 * (src[0] + src[2]) + 4;
      t2 = 17 * (src[0] - src[2]) + 4;
      t3 = 22 * src[1] + 10 * src[3];
      t4 = 22 * src[3] - 10 * src[1];
      dst[0] = (t1 + t3) >> 3;
      dst[1] = (t2 - t4) >> 3;
      dst[2] = (t2 + t4) >> 3;
      dst[3] = (t1 - t3) >> 3;
      src += 8;
      dst += 8;
    }
}
