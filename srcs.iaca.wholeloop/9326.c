#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int width, int pos_1_0, int x, int init_x, ptrdiff_t y_stride,
    ptrdiff_t y_stride_0_1, int pos_0_0, ptrdiff_t y_stride_1_1,
    uint8_t * dst, int *sao_offset_val, uint8_t * src,
    const uint8_t edge_idx[5])
{
  IACA_START for (x = init_x; x < width; x++)
    {
      int diff0 =
	((src[x + y_stride]) >
	 (src[x + pos_0_0 + y_stride_0_1]) ? 1 : ((src[x + y_stride]) ==
						  (src
						   [x + pos_0_0 +
						    y_stride_0_1]) ? 0 : -1));
      int diff1 =
	((src[x + y_stride]) >
	 (src[x + pos_1_0 + y_stride_1_1]) ? 1 : ((src[x + y_stride]) ==
						  (src
						   [x + pos_1_0 +
						    y_stride_1_1]) ? 0 : -1));
      int offset_val = edge_idx[2 + diff0 + diff1];
      dst[x + y_stride] =
	av_clip_uint8_c (src[x + y_stride] + sao_offset_val[offset_val]);
}IACA_END}
