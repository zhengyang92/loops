#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (PutBitContext * ac_pb, int i, int last_non_zero, int16_t * block,
    const int last_index, uint8_t * scan_table, uint8_t * len_tab,
    uint32_t * bits_tab)
{
  IACA_START for (; i < last_index; i++)
    {
      int level = block[scan_table[i]];
      if (level)
	{
	  int run = i - last_non_zero - 1;
	  level += 64;
	  if ((level & (~127)) == 0)
	    {
	      const int index = ((0) * 128 * 64 + (run) * 128 + (level));
	      put_bits (ac_pb, len_tab[index], bits_tab[index]);
	    }
	  else
	    {
	      put_bits (ac_pb, 7 + 2 + 1 + 6 + 1 + 12 + 1,
			(3 << 23) + (3 << 21) + (0 << 20) + (run << 14) +
			(1 << 13) + (((level - 64) & 0xfff) << 1) + 1);
	    }
	  last_non_zero = i;
	}
     } IACA_END
}
