#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *move, int i, float *board)
{
  for (i = 0; i < 19 * 19; ++i)
     { IACA_START
      if (board[i] || board[i + 19 * 19])
	move[i] = 0;
     } IACA_END
}
