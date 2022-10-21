#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int w2, int x, int16_t * temp, int16_t * b)
{
  for (x = 1; x < w2; x++)
     { IACA_START
      temp[x] =
	((unsigned) (b[x]) -
	 ((int) (1817 * (b[x + w2 - 1] + (unsigned) b[x + w2]) + 2048) >>
	  12));
      temp[x + w2 - 1] =
	((unsigned) (b[x + w2 - 1]) -
	 ((int) (113 * (temp[x - 1] + (unsigned) temp[x]) + 64) >> 7));
} IACA_END }
