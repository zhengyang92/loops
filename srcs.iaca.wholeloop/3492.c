#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int nb, int n, int16_t (*table)[2], int symbol, int j)
{
  int inc = 1;
  int i = 0;
  IACA_START for (int k = 0; k < nb; k++)
    {
      int bits = table[j][1];
      int oldsym = table[j][0];
      do
	{
	  if (0)
	    av_log (((void *) 0), 48, "%4x: code=%d n=%d\n", j, i, n);
	}
      while (0);
      if ((bits || oldsym) && (bits != n || oldsym != symbol))
	{
	  av_log (((void *) 0), 16, "incorrect codes\n");
	  return (-(int)
		  (('I') | (('N') << 8) | (('D') << 16) |
		   ((unsigned) ('A') << 24)));
	}
      table[j][1] = n;
      table[j][0] = symbol;
      j += inc;
}IACA_END}
