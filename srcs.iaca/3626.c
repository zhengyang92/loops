#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * right, int i, int32_t * left, int nb_samples, int shift)
{
  for (i = 0; i < nb_samples; i++)
    {
      left[i] >>= shift;
      right[i] >>= shift;
    }
}
