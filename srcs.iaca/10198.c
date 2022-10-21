#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned char U8;
typedef int Bool;

int
fn (I32 x, I32 n, Bool bBlackWhite, U8 * piDstPixel, const U8 v)
{
  for (n = 0; n < 8; n++)
     { IACA_START
      piDstPixel[8 * x + n] =
	(((v >> (7 - n)) & 0x1) != 0) ^ bBlackWhite ? 0xFF : 0x00;
     } IACA_END
}
