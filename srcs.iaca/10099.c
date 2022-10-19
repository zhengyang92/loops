#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, uint32_t count, uint32_t * const counts, uint32_t k,
    uint32_t stride)
{
  for (k = 0; k < stride; ++k)
    {
      counts[i - k - 1] = count;
    }
}
