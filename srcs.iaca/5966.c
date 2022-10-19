#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int dcv, int x, uint8_t * dest_cr, int *linesize,
    uint8_t * dest_cb, int dcu)
{
  for (x = 0; x < 8; x++)
    {
      dcu += dest_cb[x + y * linesize[1]];
      dcv += dest_cr[x + y * linesize[2]];
    }
}
