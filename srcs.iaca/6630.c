#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int distortion, int level, int last_i, int survivor[65], int j,
    int score_tab[65], int survivor_count)
{
  int last_level = 0;
  int last_run = 0;
  int last_score = 0;
  for (j = survivor_count - 1; j >= 0; j--)
    {
      int run = i - survivor[j];
      int score = distortion + score_tab[i - run];
      if (score < last_score)
	{
	  last_score = score;
	  last_run = run;
	  last_level = level - 64;
	  last_i = i + 1;
	}
    }
}
