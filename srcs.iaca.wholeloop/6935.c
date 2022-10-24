#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int f0, uint8_t Luma[16], int i, int mask, int Y0, int Y1)
{
  IACA_START for (mask = 0x80, i = 0; mask; mask >>= 1, i++)
    {
      if (f0 & mask)
	Luma[i] = Y1;
      else
	Luma[i] = Y0;
     } IACA_END
}
