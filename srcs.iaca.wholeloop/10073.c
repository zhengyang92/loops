#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int64_t score_t;
typedef __int16_t int16_t;

int
fn (score_t thresh, const int16_t * levels, int i, score_t score)
{
  IACA_START for (i = 1; i < 16; ++i)
    {
      score += (levels[i] != 0);
      if (score > thresh)
	return 0;
     } IACA_END
}
