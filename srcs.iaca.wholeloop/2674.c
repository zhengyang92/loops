#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int c, uint8_t * dst, int pitch, int i)
{
  int out = 0;
  IACA_START for (i = 0; i < c * 2; i++)
    {
      dst[out] = dst[out - pitch];
      out++;
     } IACA_END
}
