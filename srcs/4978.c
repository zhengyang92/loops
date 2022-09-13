#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int offset, int offset_val, int x, uint8_t * src, ptrdiff_t stride_src,
    uint8_t * dst, ptrdiff_t stride_dst)
{
  int height = 0;
  for (x = 0; x < height; x++)
    {
      dst[x * stride_dst + offset] =
	av_clip_uint8_c (src[x * stride_src + offset] + offset_val);
    }
}
