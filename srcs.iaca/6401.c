#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int i, int val, uint8_t * dst, int repeat, GetBitContext * gb)
{
  for (i = 0; i < 256;)
    {
      repeat = get_bits (gb, 3);
      val = get_bits (gb, 5);
      if (repeat == 0)
	repeat = get_bits (gb, 8);
      if (i + repeat > 256 || get_bits_left (gb) < 0)
	{
	  av_log (((void *) 0), 16, "Error reading huffman table\n");
	  return (-0x3ebbb1b7);
	}
      while (repeat--)
	dst[i++] = val;
    }
}
