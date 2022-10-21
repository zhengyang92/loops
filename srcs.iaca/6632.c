#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int lambda, int survivor[65], int score_tab[65], int best_score,
    int survivor_count)
{
  for (; survivor_count; survivor_count--)
     { IACA_START
      if (score_tab[survivor[survivor_count - 1]] <= best_score + lambda)
	break;
     } IACA_END
}
