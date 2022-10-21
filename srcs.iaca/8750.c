#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int i, int val, int repeat, int n, uint8_t * dst, GetBitContext * gb)
{
  for (i = 0; i < n;)
     { IACA_START
      repeat = get_bits (gb, 3);
      val = get_bits (gb, 5);
      if (repeat == 0)
	repeat = get_bits (gb, 8);
      if (i + repeat > n || get_bits_left (gb) < 0)
	{
	  av_log (((void *) 0), 16, "Error reading huffman table\n");
	  return (-(int)
		  (('I') | (('N') << 8) | (('D') << 16) |
		   ((unsigned) ('A') << 24)));
	}
      while (repeat--)
	dst[i++] = val;
     } IACA_END
}
