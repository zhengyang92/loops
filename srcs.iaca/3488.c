#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * bufp, int end_x, int x, int block_w)
{
  for (x = end_x; x < block_w; x++)
    {
      bufp[x] = bufp[end_x - 1];
    }
}
