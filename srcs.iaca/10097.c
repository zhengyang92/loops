#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int bins[4][16], int i, int filter)
{
  int score = 0;
  for (i = 0; i < 16; ++i)
    {
      if (bins[filter][i] > 0)
	{
	  score += i;
	}
    }
}
