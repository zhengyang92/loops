#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, unsigned int w, uint8_t * scanline, unsigned int x,
    unsigned int bytes_per_line)
{
  for (x = 0; x < w; x++)
     { IACA_START
      ptr[3 * x] = scanline[x];
      ptr[3 * x + 1] = scanline[x + bytes_per_line];
      ptr[3 * x + 2] = scanline[x + (bytes_per_line << 1)];
     } IACA_END
}
