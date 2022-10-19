#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int last_non_zero, const int lambda, int level_tab[65],
    int run_tab[65], int last_i, int survivor[65], int score_tab[65])
{
  int last_level = 0;
  int last_run = 0;
  int last_score = 0;
  for (i = survivor[0]; i <= last_non_zero + 1; i++)
    {
      int score = score_tab[i];
      if (i)
	score += lambda * 2;
      if (score < last_score)
	{
	  last_score = score;
	  last_i = i;
	  last_level = level_tab[i];
	  last_run = run_tab[i];
	}
    }
}
