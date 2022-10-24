#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * planep, int x, int width, uint8_t invert, int stride)
{
  IACA_START for (x = 1; x < width; x++)
    {
      if (planep[x - 1] != planep[x - stride])
	planep[x] ^= invert;
      else
	planep[x] ^= planep[x - 1];
     } IACA_END
}