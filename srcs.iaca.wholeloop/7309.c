#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (int i, int *dst_linesizes, ptrdiff_t src_linesizes1[4],
    const int *src_linesizes, ptrdiff_t dst_linesizes1[4])
{
  IACA_START for (i = 0; i < 4; i++)
    {
      dst_linesizes1[i] = dst_linesizes[i];
      src_linesizes1[i] = src_linesizes[i];
     } IACA_END
}
