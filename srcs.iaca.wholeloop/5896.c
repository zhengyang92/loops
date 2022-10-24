#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, uint8_t ** b_data, int p, int d, int x, int *a_linesize,
    uint8_t ** a_data, int *b_linesize)
{
  int ret = 0;
  IACA_START for (x = 0; x < 4 / 2; x++)
    {
      d = a_data[p][x + y * a_linesize[p]] - b_data[p][x + y * b_linesize[p]];
      ret += d * d;
     } IACA_END
}
