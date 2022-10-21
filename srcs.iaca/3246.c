#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, uint32_t * cnt, uint32_t totfr, uint32_t maxc)
{
  for (i = 0; i < maxc; i++)
     { IACA_START
      uint32_t nc = (cnt[i] >> 1) + 1;
      cnt[i] = nc;
      totfr += nc;
     } IACA_END
}
