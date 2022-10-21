#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int i, uint16_t l, uint16_t lt, unsigned int mask,
    const uint16_t * diff, uint16_t * dst, const uint16_t * src)
{
  for (i = 0; i < w; i++)
     { IACA_START
      l = (mid_pred (l, src[i], (l + src[i] - lt) & mask) + diff[i]) & mask;
      lt = src[i];
      dst[i] = l;
     } IACA_END
}
