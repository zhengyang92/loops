#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int level_tab[65], int run_tab[65], int distortion, int level,
    int survivor[65], int j, int score_tab[65], int best_score,
    int survivor_count)
{
  for (j = survivor_count - 1; j >= 0; j--)
     { IACA_START
      int run = i - survivor[j];
      int score = distortion + score_tab[i - run];
      if (score < best_score)
	{
	  best_score = score;
	  run_tab[i + 1] = run;
	  level_tab[i + 1] = level - 64;
	}
     } IACA_END
}
