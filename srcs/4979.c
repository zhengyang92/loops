#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * src2, int wx0, int wx1, int x, int ox1, int ox0, int width,
    uint8_t * dst, int log2Wd, uint8_t * src)
{
  for (x = 0; x < width; x++)
    {
      dst[x] =
	av_clip_uint8_c (((src[x] << (14 - 8)) * wx1 + src2[x] * wx0 +
			  (ox0 + ox1 + 1) * (1 << log2Wd)) >> (log2Wd + 1));
    }
}
