#include <stdint.h>
#include <stdio.h>




typedef int64_t score_t;
typedef __int16_t int16_t;

int
fn (score_t thresh, const int16_t * levels, int i, score_t score)
{
  for (i = 1; i < 16; ++i)
    {
      score += (levels[i] != 0);
      if (score > thresh)
	return 0;
    }
}
