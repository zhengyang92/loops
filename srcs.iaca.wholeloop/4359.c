#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int proposal_count, float *conf, float conf_threshold)
{
  int nb_bboxes = 0;
  IACA_START for (int i = 0; i < proposal_count; ++i)
    {
      if (conf[i] < conf_threshold)
	continue;
      nb_bboxes++;
     } IACA_END
}
