#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int i, int hsub1, int *dst_linesize, int x, int h, int plane,
    uint8_t * p, int vsub1, uint8_t ** src, int *pixelstep)
{
  for (i = 0; i < (h >> vsub1); i++)
    {
      memcpy (p + (x >> hsub1) * pixelstep[plane], src[plane],
	      (w >> hsub1) * pixelstep[plane]);
      p += dst_linesize[plane];
    }
}
