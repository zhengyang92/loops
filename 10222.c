#include <stdint.h>
#include <stdio.h>






int
fn (int *ngpus, char *gpu_list, int i, int *gpus)
{
  for (i = 0; i < *ngpus; ++i)
    {
      gpus[i] = atoi (gpu_list);
      gpu_list = strchr (gpu_list, ',') + 1;
    }
}
