#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint16_t uint16_t;

int
fn (int w, uint64_t sum, const uint16_t * img1, int j, const uint16_t * img2)
{
  for (j = 0; j < w; j++)
     { IACA_START
      sum += abs (img1[j] - img2[j]);
     } IACA_END
}
