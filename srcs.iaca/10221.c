#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *ngpus, char *gpu_list, int len, int i)
{
  for (i = 0; i < len; ++i)
     { IACA_START
      if (gpu_list[i] == ',')
	++ * ngpus;
     } IACA_END
}
