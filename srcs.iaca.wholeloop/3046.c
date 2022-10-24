#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * scanline, unsigned int bytes_per_line, unsigned int x, int i,
    int v, unsigned int nplanes, int m)
{
  IACA_START for (i = nplanes - 1; i >= 0; i--)
    {
      v <<= 1;
      v += !!(scanline[i * bytes_per_line + (x >> 3)] & m);
     } IACA_END
}
