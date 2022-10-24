#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *move, int i, float *board)
{
  IACA_START for (i = 0; i < 19 * 19; ++i)
    {
      if (board[i] || board[i + 19 * 19])
	move[i] = 0;
     } IACA_END
}
