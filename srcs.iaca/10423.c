#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (char *gpu_list, int i, int *gpus)
{
  int ngpus = 0;
  for (i = 0; i < ngpus; ++i)
     { IACA_START
      gpus[i] = atoi (gpu_list);
      gpu_list = strchr (gpu_list, ',') + 1;
     } IACA_END
}
