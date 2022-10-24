#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int offset, int offset_val, int x, uint16_t * src, ptrdiff_t stride_src,
    uint16_t * dst, ptrdiff_t stride_dst)
{
  int height = 0;
  IACA_START for (x = 0; x < height; x++)
    {
      dst[x * stride_dst + offset] =
	av_clip_uintp2_c (src[x * stride_src + offset] + offset_val, 9);
     } IACA_END
}
