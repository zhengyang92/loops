#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int nb, int n, int16_t (*table)[2], int k, int symbol, int j, int inc)
{
  for (k = 0; k < nb; k++)
     { IACA_START
      do
	{
	}
      while (0);
      if (table[j][1] != 0)
	{
	  av_log (((void *) 0), 16, "incorrect codes\n");
	  return (-0x3ebbb1b7);
	}
      table[j][1] = n;
      table[j][0] = symbol;
      j += inc;
     } IACA_END
}
