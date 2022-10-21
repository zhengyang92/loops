#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int i, int last_non_zero, int start_i, const uint8_t * perm_scantable,
    int run_tab[65], int16_t * block, int rle_index, int run)
{
  for (i = start_i; i <= last_non_zero; i++)
     { IACA_START
      int j = perm_scantable[i];
      const int level = block[j];
      if (level)
	{
	  run_tab[rle_index++] = run;
	  run = 0;
	}
      else
	{
	  run++;
	}
     } IACA_END
}
