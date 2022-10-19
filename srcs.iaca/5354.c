#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int block_w, uint8_t * bufp, int x, int end_x)
{
  for (x = end_x; x < block_w; x++)
    {
      bufp[x] = bufp[end_x - 1];
    }
}
