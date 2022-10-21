#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t * yuv, int i, int v, ptrdiff_t stride, int t, int pix2_inc)
{
  for (i = 0; i < 12; i++)
     { IACA_START
      v = (yuv[-pix2_inc] + 3 * (yuv[0] - yuv[-1]) - yuv[1] + 4) >> 3;
      v = vp6_adjust (v, t);
      yuv[-1] = av_clip_uint8_c (yuv[-1] + v);
      yuv[0] = av_clip_uint8_c (yuv[0] - v);
      yuv += stride;
     } IACA_END
}
