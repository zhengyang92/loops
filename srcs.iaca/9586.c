#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int i, uint8_t * dest, ptrdiff_t stride, int t3, int16_t * src, int t1,
    int t4, int t2)
{
  for (i = 0; i < 8; i++)
    {
      t1 = 17 * (src[0] + src[16]) + 64;
      t2 = 17 * (src[0] - src[16]) + 64;
      t3 = 22 * src[8] + 10 * src[24];
      t4 = 22 * src[24] - 10 * src[8];
      dest[0 * stride] =
	av_clip_uint8_c (dest[0 * stride] + ((t1 + t3) >> 7));
      dest[1 * stride] =
	av_clip_uint8_c (dest[1 * stride] + ((t2 - t4) >> 7));
      dest[2 * stride] =
	av_clip_uint8_c (dest[2 * stride] + ((t2 + t4) >> 7));
      dest[3 * stride] =
	av_clip_uint8_c (dest[3 * stride] + ((t1 - t3) >> 7));
      src++;
      dest++;
    }
}
