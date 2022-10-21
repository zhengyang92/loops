#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int ny, const int my, int i, int best_pos[8][2], int score, int nx,
    const int mx, int best[8])
{
  for (i = 0; i < 8; i++)
     { IACA_START
      if (score < best[i])
	{
	  memmove (&best[i + 1], &best[i], sizeof (int) * (7 - i));
	  memmove (&best_pos[i + 1][0], &best_pos[i][0],
		   sizeof (int) * 2 * (7 - i));
	  best[i] = score;
	  best_pos[i][0] = nx + 4 * mx;
	  best_pos[i][1] = ny + 4 * my;
	  break;
	}
     } IACA_END
}
