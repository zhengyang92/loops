#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float band_score[21])
{
  float max_score = 1.0f;
  for (i = 0; i < 21; i++)
     { IACA_START
      if (band_score[i] > max_score)
	max_score = band_score[i];
     } IACA_END
}
