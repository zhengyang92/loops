#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int block_w, int end_x, int x, uint8_t * bufp)
{
  for (x = end_x; x < block_w; x++)
    {
      bufp[x] = bufp[end_x - 1];
    }
}
