#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * c8, const int *const matrix, const uint8_t * c4,
    const uint8_t * c5, float rdiv, int x, int width, const uint8_t * c7,
    const uint8_t * c3, float bias, const uint8_t * c1, uint8_t * dst,
    const uint8_t * c0, const uint8_t * c6, const uint8_t * c2)
{
  for (x = 0; x < width; x++)
     { IACA_START
      int sum =
	c0[x] * matrix[0] + c1[x] * matrix[1] + c2[x] * matrix[2] +
	c3[x] * matrix[3] + c4[x] * matrix[4] + c5[x] * matrix[5] +
	c6[x] * matrix[6] + c7[x] * matrix[7] + c8[x] * matrix[8];
      sum = (int) (sum * rdiv + bias + 0.5f);
      dst[x] = av_clip_uint8_c (sum);
} IACA_END }
