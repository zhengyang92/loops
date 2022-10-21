#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t w, int i, const uint8_t * diff, uint8_t * dst,
    const uint8_t * src1, uint8_t lt, uint8_t l)
{
  for (i = 0; i < w; i++)
     { IACA_START
      l = mid_pred (l, src1[i], (l + src1[i] - lt) & 0xFF) + diff[i];
      lt = src1[i];
      dst[i] = l;
     } IACA_END
}
