#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t maxc, uint32_t * cnt, int i, uint32_t totfr)
{
  for (i = 0; i < maxc; i++)
     { IACA_START
      uint32_t nc = (cnt[i] >> 1) + 1;
      cnt[i] = nc;
      totfr += nc;
     } IACA_END
}
