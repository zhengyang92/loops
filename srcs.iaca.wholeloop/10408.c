#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (char *gpu_list, int len, int i)
{
  int ngpus = 0;
  IACA_START for (i = 0; i < len; ++i)
    {
      if (gpu_list[i] == ',')
	++ngpus;
     } IACA_END
}
