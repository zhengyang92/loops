#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (char *gpu_list, int len, int i)
{
  int ngpus = 0;
  for (i = 0; i < len; ++i)
     { IACA_START
      if (gpu_list[i] == ',')
	++ngpus;
     } IACA_END
}
