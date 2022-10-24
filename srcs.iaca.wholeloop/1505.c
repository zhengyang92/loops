#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int *quants, const uint8_t aac_cb_range[12], const int dim, int off,
    int cb, int j)
{
  int curidx = 0;
  IACA_START for (j = 0; j < dim; j++)
    {
      curidx *= aac_cb_range[cb];
      curidx += quants[j] + off;
     } IACA_END
}
