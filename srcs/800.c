#include <stdint.h>
#include <stdio.h>






int
fn (float conf_threshold, float *conf, int proposal_count)
{
  int nb_bboxes = 0;
  for (int i = 0; i < proposal_count; ++i)
    {
      if (conf[i] < conf_threshold)
	continue;
      nb_bboxes++;
    }
}
