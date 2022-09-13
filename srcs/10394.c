#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float *board, char *s)
{
  int count = 0;
  for (j = 0; j < 4; ++j)
    {
      int me = (board[count] == 1);
      int you = (board[count + 19 * 19] == 1);
      if (me)
	s[i] = s[i] | (1 << (2 * j));
      if (you)
	s[i] = s[i] | (1 << (2 * j + 1));
      ++count;
      if (count >= 19 * 19)
	break;
    }
}
