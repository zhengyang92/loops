#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, int srcStride, const uint8_t * src, uint8_t * dst)
{
  const int h = 8;
  for (i = 0; i < h; i++)
    {
      dst[0] =
	av_clip_uint8_c ((((src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 +
			   (src[-2] + src[3])) + 16) >> 5);
      dst[1] =
	av_clip_uint8_c ((((src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 +
			   (src[-1] + src[4])) + 16) >> 5);
      dst[2] =
	av_clip_uint8_c ((((src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 +
			   (src[0] + src[5])) + 16) >> 5);
      dst[3] =
	av_clip_uint8_c ((((src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 +
			   (src[1] + src[6])) + 16) >> 5);
      dst[4] =
	av_clip_uint8_c ((((src[4] + src[5]) * 20 - (src[3] + src[6]) * 5 +
			   (src[2] + src[7])) + 16) >> 5);
      dst[5] =
	av_clip_uint8_c ((((src[5] + src[6]) * 20 - (src[4] + src[7]) * 5 +
			   (src[3] + src[8])) + 16) >> 5);
      dst[6] =
	av_clip_uint8_c ((((src[6] + src[7]) * 20 - (src[5] + src[8]) * 5 +
			   (src[4] + src[9])) + 16) >> 5);
      dst[7] =
	av_clip_uint8_c ((((src[7] + src[8]) * 20 - (src[6] + src[9]) * 5 +
			   (src[5] + src[10])) + 16) >> 5);
      dst += dstStride;
      src += srcStride;
    }
}
