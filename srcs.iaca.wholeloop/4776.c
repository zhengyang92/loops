#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int tile_width, int i, uint8_t * out, uint32_t * in)
{
  IACA_START for (i = 0; i < tile_width; i++)
    {
      out[0] = (in[i] >> 16) & 0xFF;
      out[1] = (in[i] >> 8) & 0xFF;
      out[2] = (in[i] >> 0) & 0xFF;
      out += 3;
     } IACA_END
}
