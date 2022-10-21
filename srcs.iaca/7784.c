#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef RangeCoder;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int v, RangeCoder * c, int16_t * quant_table, uint8_t state[32],
    int scale)
{
  int i = 0;
  for (v = 0; i < 128; v++)
     { IACA_START
      unsigned len = get_symbol (c, state, 0) + 1U;
      if (len > 128 - i || !len)
	return (-(int)
		(('I') | (('N') << 8) | (('D') << 16) |
		 ((unsigned) ('A') << 24)));
      while (len--)
	{
	  quant_table[i] = scale * v;
	  i++;
	}
     } IACA_END
}
