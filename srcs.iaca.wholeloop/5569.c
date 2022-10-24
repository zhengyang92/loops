#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int i, int hsub1, int *dst_linesize, int x, int h, int plane,
    int *src_linesize, int y2, uint8_t * p, int vsub1, uint8_t ** src,
    int *pixelstep)
{
  IACA_START for (i = 0; i < (h >> vsub1); i++)
    {
      memcpy (p + (x >> hsub1) * pixelstep[plane],
	      src[plane] + src_linesize[plane] * (i + (y2 >> vsub1)),
	      (w >> hsub1) * pixelstep[plane]);
      p += dst_linesize[plane];
     } IACA_END
}
