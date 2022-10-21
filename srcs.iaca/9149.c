#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t ** b_data, int y, int d, int x, int *a_linesize,
    uint8_t ** a_data, int *b_linesize)
{
  int ret = 0;
  for (x = 0; x < 4; x++)
     { IACA_START
      d = a_data[0][x + y * a_linesize[0]] - b_data[0][x + y * b_linesize[0]];
      ret += d * d;
     } IACA_END
}
