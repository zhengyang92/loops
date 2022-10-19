#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * src2, int i, uint8_t * src)
{
  for (i = 0; i < 9; i++)
    {
      src[i] = ((src[i] - 128) >> 1) + 128;
      src2[i] = ((src2[i] - 128) >> 1) + 128;
    }
}
