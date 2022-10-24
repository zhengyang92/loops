#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int yz, int xy, int x, int temp[64], uint8_t * src, int stride)
{
  IACA_START for (x = 1; x < 7; x++)
    {
      xy = y * stride + x;
      yz = y * 8 + x;
      src[xy] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
     } IACA_END
}