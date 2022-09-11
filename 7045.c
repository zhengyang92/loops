#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (int b1, int d1, int i, ptrdiff_t stride, int c1, int16_t tmp[16], int a1,
    uint8_t * dst)
{
  for (i = 0; i < 4; i++)
    {
      a1 = (tmp[i + 0] + tmp[i + 8]) * 23170;
      b1 = (tmp[i + 0] - tmp[i + 8]) * 23170;
      c1 = tmp[i + 4] * 12540 - tmp[i + 12] * 30274;
      d1 = tmp[i + 4] * 30274 + tmp[i + 12] * 12540;
      dst[0 * stride + i] =
	av_clip_uint8_c (dst[0 * stride + i] + ((a1 + d1 + 0x20000) >> 18));
      dst[3 * stride + i] =
	av_clip_uint8_c (dst[3 * stride + i] + ((a1 - d1 + 0x20000) >> 18));
      dst[1 * stride + i] =
	av_clip_uint8_c (dst[1 * stride + i] + ((b1 + c1 + 0x20000) >> 18));
      dst[2 * stride + i] =
	av_clip_uint8_c (dst[2 * stride + i] + ((b1 - c1 + 0x20000) >> 18));
    }
}
