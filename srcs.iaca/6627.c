#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const int lambda, int level_tab[65], int run_tab[65],
    int distortion, int level, uint8_t * length, int survivor[65], int j,
    int score_tab[65], int best_score, int survivor_count)
{
  for (j = survivor_count - 1; j >= 0; j--)
    {
      int run = i - survivor[j];
      int score = distortion + length[((run) * 128 + (level))] * lambda;
      score += score_tab[i - run];
      if (score < best_score)
	{
	  best_score = score;
	  run_tab[i + 1] = run;
	  level_tab[i + 1] = level - 64;
	}
    }
}
