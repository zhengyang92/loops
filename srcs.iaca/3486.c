#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int32_t dwtcoef;
typedef long int ptrdiff_t;

int
fn (const ptrdiff_t synth_width, int y, dwtcoef * synthl, int x,
    const ptrdiff_t synth_height)
{
  for (y = 0; y < synth_height; y += 2)
    {
      synthl[(y + 1) * synth_width + x] =
	synthl[(y + 1) * synth_width + x] - synthl[y * synth_width + x];
      synthl[y * synth_width + x] =
	synthl[y * synth_width + x] +
	((synthl[(y + 1) * synth_width + x] + 1) >> 1);
    }
}
