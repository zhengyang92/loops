#include <stdint.h>
#include <stdio.h>






int
fn (char c, int j, float *board)
{
  int count = 0;
  for (j = 0; j < 4; ++j)
    {
      int me = (c >> (2 * j)) & 1;
      int you = (c >> (2 * j + 1)) & 1;
      if (me)
	board[count] = 1;
      else if (you)
	board[count + 19 * 19] = 1;
      ++count;
      if (count >= 19 * 19)
	break;
    }
}
