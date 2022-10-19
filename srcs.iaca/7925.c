#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int16_t * sao_offset_val, uint16_t * dst, int width, int x,
    uint16_t * src, int a_stride, int b_stride, const uint8_t edge_idx[5])
{
  for (x = 0; x < width; x++)
    {
      int diff0 =
	(((src[x]) > (src[x + a_stride])) - ((src[x]) < (src[x + a_stride])));
      int diff1 =
	(((src[x]) > (src[x + b_stride])) - ((src[x]) < (src[x + b_stride])));
      int offset_val = edge_idx[2 + diff0 + diff1];
      dst[x] = av_clip_uintp2_c (src[x] + sao_offset_val[offset_val], 9);
}}
