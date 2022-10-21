#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int length, uint32_t pattern, uint8_t * dst, int i)
{
  for (i = 0; i < (length >> 2); ++i)
     { IACA_START
      ((uint32_t *) dst)[i] = pattern;
     } IACA_END
}
