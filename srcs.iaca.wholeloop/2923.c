#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int last_non_zero, int start_i, int16_t * block, int run_tab[65],
    const uint8_t * perm_scantable, int rle_index, int run)
{
  IACA_START for (i = start_i; i <= last_non_zero; i++)
    {
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
