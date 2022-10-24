#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *board)
{
  IACA_START for (i = 0; i < 19 * 19; ++i)
    {
      float swap = board[i];
      board[i] = board[i + 19 * 19];
      board[i + 19 * 19] = swap;
      board[i + 19 * 19 * 2] = 1 - board[i + 19 * 19 * 2];
}IACA_END}
