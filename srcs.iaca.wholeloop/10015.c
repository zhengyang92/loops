#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VP8LColorCache;
typedef __uint32_t uint32_t;

int
fn (const uint32_t * const argb, VP8LColorCache hashers, int k, const int len)
{
  int i = 0;
  IACA_START for (k = 0; k < len; ++k)
    {
      VP8LColorCacheInsert (&hashers, argb[i + k]);
     } IACA_END
}
