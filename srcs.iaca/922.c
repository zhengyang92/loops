#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int x, int w, const uint16_t * src, float *histogram)
{
  for (x = 0; x < w; x++)
     { IACA_START
      histogram[src[x]] += 1;
     } IACA_END
}
