#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef VP8LColorCache;

int
fn (const uint32_t * const argb, int i, const int prev_row_len, int k,
    VP8LColorCache hashers)
{
  for (k = 0; k < prev_row_len; ++k)
    {
      VP8LColorCacheInsert (&hashers, argb[i + k]);
    }
}
