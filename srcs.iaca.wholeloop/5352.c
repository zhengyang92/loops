#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef int32_t dwtcoef;

int
fn (const ptrdiff_t synth_width, const int s, int y, ptrdiff_t stride, int x,
    dwtcoef * synthl, dwtcoef * datal)
{
  IACA_START for (x = 0; x < synth_width; x += 2)
    {
      synthl[y * synth_width + x + 1] =
	(datal[y * stride + x + 1] << s) - (datal[y * stride + x] << s);
      synthl[y * synth_width + x] =
	(datal[y * stride + x + 0] << s) +
	((synthl[y * synth_width + x + 1] + 1) >> 1);
     } IACA_END
}
