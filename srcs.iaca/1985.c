#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int dcv, int x, uint8_t * dest_cr, int *linesize,
    uint8_t * dest_cb, int dcu)
{
  for (x = 0; x < 8; x++)
     { IACA_START
      dest_cb[x + y * linesize[1]] = dcu / 8;
      dest_cr[x + y * linesize[2]] = dcv / 8;
     } IACA_END
}
