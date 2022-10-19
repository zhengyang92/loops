#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVPixFmtDescriptor;

int
fn (int *linesizes, const AVPixFmtDescriptor * desc, int i, int ret,
    int width, int max_step[4], int max_step_comp[4])
{
  for (i = 0; i < 4; i++)
    {
      if ((ret =
	   image_get_linesize (width, i, max_step[i], max_step_comp[i],
			       desc)) < 0)
	return ret;
      linesizes[i] = ret;
    }
}
