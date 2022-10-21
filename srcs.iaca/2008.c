#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t * freq, int i, uint64_t n[59])
{
  for (i = 0; i < ((1 << 16) + 1); ++i)
     { IACA_START
      int l = freq[i];
      if (l > 0)
	freq[i] = l | (n[l]++ << 6);
     } IACA_END
}
