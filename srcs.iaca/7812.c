#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int yz, int xy, int x, int temp[64], uint8_t * src, int stride)
{
  for (x = 0; x < 8; x++)
    {
      xy = y * stride + x;
      yz = y * 8 + x;
      temp[yz] = src[xy - stride] + 2 * src[xy] + src[xy + stride];
    }
}
