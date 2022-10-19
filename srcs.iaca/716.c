#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *light, int plane)
{
  for (plane = 0; plane < 3; ++plane)
    {
      light[plane] = 1.0;
    }
}
