#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * inrow, int w, int j, uint16_t * outrow, const uint16_t * tab)
{
  for (j = 0; j < w; j++)
    {
      outrow[j] = tab[inrow[j]];
    }
}
