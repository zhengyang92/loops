#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int score[8], int best_score, int best_fcode, int i)
{
  for (i = 1; i < 8; i++)
     { IACA_START
      if (score[i] > best_score)
	{
	  best_score = score[i];
	  best_fcode = i;
	}
     } IACA_END
}
