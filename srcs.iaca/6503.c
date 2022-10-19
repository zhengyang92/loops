#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int max_order, double *ref, int i, double gen1[32], double gen0[32],
    int j)
{
  for (j = 0; j < max_order - i; j++)
    {
      gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
      gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
    }
}
