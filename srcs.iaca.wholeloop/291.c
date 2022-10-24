#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int x, int w, int *(*rnd_scratch)[2], const int rnd)
{
  IACA_START for (x = 0; x < w; x++)
    {
      rnd_scratch[0][0][x] = rnd_scratch[0][1][x] = rnd;
     } IACA_END
}
