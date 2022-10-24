#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int bytes_per_line, uint8_t * scanline, int v, unsigned int x,
    int i, unsigned int nplanes, int m)
{
  IACA_START for (i = nplanes - 1; i >= 0; i--)
    {
      v <<= 1;
      v += !!(scanline[i * bytes_per_line + (x >> 3)] & m);
     } IACA_END
}
