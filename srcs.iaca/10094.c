#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int width, int i, uint32_t * const dst, int left)
{
  for (i = left; i < left + width; ++i)
     { IACA_START
      dst[i] = 0x00000000;
     } IACA_END
}
