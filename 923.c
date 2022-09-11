#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (float *histogram2, int i, float *histogram1, size_t hsize, int j)
{
  for (j = 0; j < hsize && histogram2[j] < histogram1[i]; j++);
}
