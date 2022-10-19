#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const top, int i, const uint8_t * const blk)
{
  for (i = 0; i <= 3; ++i)
    {
      top[-4 + i] = blk[i + 3 * 32];
    }
}
