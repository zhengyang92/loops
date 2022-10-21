#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t score[4], int best, int i)
{
  for (i = 1; i < 4; i++)
     { IACA_START
      if (score[i] < score[best])
	best = i;
     } IACA_END
}
