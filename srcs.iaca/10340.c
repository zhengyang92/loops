#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef image;

int
fn (int j, int i, int k, float scale[3], image im, float val)
{
  for (k = 0; k < 3; ++k)
     { IACA_START
      val += scale[k] * get_pixel (im, i, j, k);
     } IACA_END
}
