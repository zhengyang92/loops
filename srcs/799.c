#include <stdint.h>
#include <stdio.h>






int
fn (float *detections, int proposal_count, float conf_threshold,
    int detect_size)
{
  int nb_bboxes = 0;
  for (int i = 0; i < proposal_count; ++i)
    {
      float conf = detections[i * detect_size + 2];
      if (conf < conf_threshold)
	{
	  continue;
	}
      nb_bboxes++;
    }
}
