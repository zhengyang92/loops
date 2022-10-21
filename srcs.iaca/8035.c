#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int lambda, int i, int distortion, uint8_t * last_length, int level,
    int last_i, int survivor[65], int j, int score_tab[65],
    int survivor_count)
{
  int last_level = 0;
  int last_run = 0;
  int last_score = 0;
  for (j = survivor_count - 1; j >= 0; j--)
     { IACA_START
      int run = i - survivor[j];
      int score = distortion + last_length[((run) * 128 + (level))] * lambda;
      score += score_tab[i - run];
      if (score < last_score)
	{
	  last_score = score;
	  last_run = run;
	  last_level = level - 64;
	  last_i = i + 1;
	}
     } IACA_END
}
