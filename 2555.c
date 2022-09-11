#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int y, int offset_val, uint8_t * src, ptrdiff_t stride_src, uint8_t * dst,
    ptrdiff_t stride_dst)
{
  int height = 0;
  for (y = 0; y < height; y++)
    {
      dst[y * stride_dst] =
	av_clip_uint8_c (src[y * stride_src] + offset_val);
    }
}
