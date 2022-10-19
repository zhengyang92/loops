#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const good_for_rle, int k, int i)
{
  int stride = 0;
  for (k = 0; k < stride; ++k)
    {
      good_for_rle[i - k - 1] = 1;
    }
}
