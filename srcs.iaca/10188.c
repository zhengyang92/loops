#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef short I16;
typedef unsigned int U32;

int
fn (const I32 iWidth, I32 x, const I16 * piSrcPixel, U32 * pfltDstPixel)
{
  for (x = iWidth - 1; x >= 0; x--)
    {
      pfltDstPixel[3 * x] = Convert_Half_To_Float (piSrcPixel[4 * x]);
      pfltDstPixel[3 * x + 1] = Convert_Half_To_Float (piSrcPixel[4 * x + 1]);
      pfltDstPixel[3 * x + 2] = Convert_Half_To_Float (piSrcPixel[4 * x + 2]);
    }
}
