#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, unsigned int shift, uint32_t * src32, unsigned int len,
    const uint32_t mask)
{
  for (i = 0; i < len; i += 8)
     { IACA_START
      src32[i] = (src32[i] << shift) & mask;
      src32[i + 1] = (src32[i + 1] << shift) & mask;
      src32[i + 2] = (src32[i + 2] << shift) & mask;
      src32[i + 3] = (src32[i + 3] << shift) & mask;
      src32[i + 4] = (src32[i + 4] << shift) & mask;
      src32[i + 5] = (src32[i + 5] << shift) & mask;
      src32[i + 6] = (src32[i + 6] << shift) & mask;
      src32[i + 7] = (src32[i + 7] << shift) & mask;
     } IACA_END
}
