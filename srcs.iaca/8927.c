#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int i, uint32_t ncolors, uint8_t red, uint8_t green, uint8_t blue,
    GetByteContext gb, uint32_t * dst)
{
  for (i = 0; i < ncolors; i++)
     { IACA_START
      bytestream2_skipu (&gb, 4);
      red = bytestream2_get_byteu (&gb);
      bytestream2_skipu (&gb, 1);
      green = bytestream2_get_byteu (&gb);
      bytestream2_skipu (&gb, 1);
      blue = bytestream2_get_byteu (&gb);
      bytestream2_skipu (&gb, 3);
      dst[i] = 0xFFU << 24 | red << 16 | green << 8 | blue;
     } IACA_END
}
