#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * sao_offset_val, int x, int width, int a_stride, uint8_t * dst,
    int b_stride, uint8_t * src, const uint8_t edge_idx[5])
{
  for (x = 0; x < width; x++)
     { IACA_START
      int diff0 =
	(((src[x]) > (src[x + a_stride])) - ((src[x]) < (src[x + a_stride])));
      int diff1 =
	(((src[x]) > (src[x + b_stride])) - ((src[x]) < (src[x + b_stride])));
      int offset_val = edge_idx[2 + diff0 + diff1];
      dst[x] = av_clip_uint8_c (src[x] + sao_offset_val[offset_val]);
} IACA_END }
