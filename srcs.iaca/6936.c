#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t Luma[16], int i, int mask, int Y0, int f1, int Y1)
{
  for (mask = 0x80, i = 8; mask; mask >>= 1, i++)
    {
      if (f1 & mask)
	Luma[i] = Y1;
      else
	Luma[i] = Y0;
    }
}
