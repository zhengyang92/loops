#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (int i, int t6, uint8_t * dest, ptrdiff_t stride, int t3, int t8, int t5,
    int16_t * src, int t7, int t1, int t4, int t2)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      t1 = 12 * (src[0] + src[32]) + 64;
      t2 = 12 * (src[0] - src[32]) + 64;
      t3 = 16 * src[16] + 6 * src[48];
      t4 = 6 * src[16] - 16 * src[48];
      t5 = t1 + t3;
      t6 = t2 + t4;
      t7 = t2 - t4;
      t8 = t1 - t3;
      t1 = 16 * src[8] + 15 * src[24] + 9 * src[40] + 4 * src[56];
      t2 = 15 * src[8] - 4 * src[24] - 16 * src[40] - 9 * src[56];
      t3 = 9 * src[8] - 16 * src[24] + 4 * src[40] + 15 * src[56];
      t4 = 4 * src[8] - 9 * src[24] + 15 * src[40] - 16 * src[56];
      dest[0 * stride] =
	av_clip_uint8_c (dest[0 * stride] + ((t5 + t1) >> 7));
      dest[1 * stride] =
	av_clip_uint8_c (dest[1 * stride] + ((t6 + t2) >> 7));
      dest[2 * stride] =
	av_clip_uint8_c (dest[2 * stride] + ((t7 + t3) >> 7));
      dest[3 * stride] =
	av_clip_uint8_c (dest[3 * stride] + ((t8 + t4) >> 7));
      dest[4 * stride] =
	av_clip_uint8_c (dest[4 * stride] + ((t8 - t4 + 1) >> 7));
      dest[5 * stride] =
	av_clip_uint8_c (dest[5 * stride] + ((t7 - t3 + 1) >> 7));
      dest[6 * stride] =
	av_clip_uint8_c (dest[6 * stride] + ((t6 - t2 + 1) >> 7));
      dest[7 * stride] =
	av_clip_uint8_c (dest[7 * stride] + ((t5 - t1 + 1) >> 7));
      src++;
      dest++;
     } IACA_END
}
