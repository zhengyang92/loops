#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float band_score[21])
{
  float max_score = 1.0f;
  IACA_START for (i = 0; i < 21; i++)
    {
      if (band_score[i] > max_score)
	max_score = band_score[i];
     } IACA_END
}
