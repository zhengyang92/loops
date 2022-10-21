#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int t3, int16_t tmp[16], uint8_t * dst, int t0,
    int t1, int t2)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      t0 = tmp[0 * 4 + i] + tmp[2 * 4 + i];
      t1 = tmp[0 * 4 + i] - tmp[2 * 4 + i];
      t2 =
	(((tmp[1 * 4 + i]) * 35468) >> 16) -
	((((tmp[3 * 4 + i]) * 20091) >> 16) + (tmp[3 * 4 + i]));
      t3 =
	((((tmp[1 * 4 + i]) * 20091) >> 16) + (tmp[1 * 4 + i])) +
	(((tmp[3 * 4 + i]) * 35468) >> 16);
      dst[0] = av_clip_uint8_c (dst[0] + ((t0 + t3 + 4) >> 3));
      dst[1] = av_clip_uint8_c (dst[1] + ((t1 + t2 + 4) >> 3));
      dst[2] = av_clip_uint8_c (dst[2] + ((t1 - t2 + 4) >> 3));
      dst[3] = av_clip_uint8_c (dst[3] + ((t0 - t3 + 4) >> 3));
      dst += stride;
     } IACA_END
}
