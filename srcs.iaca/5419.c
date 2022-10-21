#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t pal[256], uint8_t * buf, int i, uint32_t ncolors)
{
  for (i = 0; i < ncolors; i++)
     { IACA_START
      uint32_t val;
      uint8_t red, green, blue;
      val = pal[i];
      red = (val >> 16) & 0xFF;
      green = (val >> 8) & 0xFF;
      blue = val & 0xFF;
      bytestream_put_be32 (&buf, i);
      bytestream_put_be16 (&buf, red << 8);
      bytestream_put_be16 (&buf, green << 8);
      bytestream_put_be16 (&buf, blue << 8);
      bytestream_put_byte (&buf, 0x7);
      bytestream_put_byte (&buf, 0);
     } IACA_END
}
