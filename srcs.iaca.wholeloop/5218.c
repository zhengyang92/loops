#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const int lim, const uint8_t * cm, const int stride, int diff,
    uint8_t * src, const int step)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      diff =
	((src[-2 * step] - src[1 * step]) -
	 (src[-1 * step] - src[0 * step]) * 4) >> 3;
      diff = av_clip_c (diff, -lim, lim);
      src[-1 * step] = cm[src[-1 * step] + diff];
      src[0 * step] = cm[src[0 * step] - diff];
      src += stride;
     } IACA_END
}
