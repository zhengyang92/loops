#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int pitch, uint8_t * dst, int i, int c)
{
  int out = 0;
  for (i = 0; i < c * 2; i++)
     { IACA_START
      dst[out] = dst[out - pitch];
      out++;
     } IACA_END
}
