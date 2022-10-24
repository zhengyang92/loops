#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int last_non_zero, int16_t * block, const int last_index,
    uint8_t * scan_table, uint8_t * len_tab)
{
  int len = 0;
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
	      len += len_tab[index];
	    }
	  else
	    {
	      len += 7 + 2 + 1 + 6 + 1 + 12 + 1;
	    }
	  last_non_zero = i;
	}
     } IACA_END
}
