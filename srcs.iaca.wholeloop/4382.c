#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w, const float *osrc, const float *msrc, float *dst,
    const float *bsrc)
{
  IACA_START for (int x = 0; x < w; x++)
    {
      const float invm = 1.f - msrc[x];
      const float r =
	((float) (bsrc[x] * invm) + (float) (msrc[x] * osrc[x] + 0.f)) + 0.f;
      dst[x] = r;
}IACA_END}
