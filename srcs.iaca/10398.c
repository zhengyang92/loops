#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int inverted, int indexes[10], float *move, int col, int i,
    const int nind, int row, int noi)
{
  for (i = 0; i < nind; ++i)
     { IACA_START
      int index = indexes[i];
      row = index / 19;
      col = index % 19;
      if (row == 19)
	{
	  printf ("%d: Pass, %.2f%%\n", i + 1, move[index] * 100);
	}
      else
	{
	  printf ("%d: %c %d, %.2f%%\n", i + 1,
		  col + 'A' + 1 * (col > 7
				   && noi), (inverted) ? 19 - row : row + 1,
		  move[index] * 100);
	}
     } IACA_END
}
