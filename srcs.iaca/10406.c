#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int len, char *gpu_list, int i)
{
  int ngpus = 0;
  for (i = 0; i < len; ++i)
    {
      if (gpu_list[i] == ',')
	++ngpus;
    }
}
