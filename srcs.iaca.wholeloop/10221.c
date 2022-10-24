#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *ngpus, char *gpu_list, int len, int i)
{
  IACA_START for (i = 0; i < len; ++i)
    {
      if (gpu_list[i] == ',')
	++ * ngpus;
     } IACA_END
}
