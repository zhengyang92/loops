#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int w, const uint8_t * src, float *histogram)
{
  for (x = 0; x < w; x++)
     { IACA_START
      histogram[src[x]] += 1;
     } IACA_END
}
