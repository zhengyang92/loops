#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float maxval, int w, int dst_stride, int sub, int width, float *meanA,
    const uint8_t * src, float *meanB, int src_stride, uint8_t * dst)
{
  int i = 0;
  for (int j = 0; j < width; j++)
     { IACA_START
      int x = i / sub * w + j / sub;
      dst[i * dst_stride + j] =
	meanA[x] * src[i * src_stride + j] + meanB[x] * maxval;
} IACA_END }
