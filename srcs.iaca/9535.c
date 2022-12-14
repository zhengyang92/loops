#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t * ptr, int i, ptrdiff_t stride, int step, int sum_p1p2,
    uint8_t * src)
{
  int sum_q1q2 = 0;
  for (i = 0, ptr = src; i < 4; i++, ptr += stride)
     { IACA_START
      sum_p1p2 += ptr[-2 * step] - ptr[-3 * step];
      sum_q1q2 += ptr[1 * step] - ptr[2 * step];
     } IACA_END
}
