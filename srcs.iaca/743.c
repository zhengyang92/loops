#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * c8, float delta, const uint8_t * c5, int width, int x,
    float scale, const uint8_t * c7, const uint8_t * c1, const uint8_t * c3,
    const uint8_t * c2, uint8_t * dst, const uint8_t * c0, const uint8_t * c6)
{
  for (x = 0; x < width; x++)
     { IACA_START
      int sum0 =
	c0[x] * 5 + c1[x] * 5 + c2[x] * 5 + c3[x] * -3 + c5[x] * -3 +
	c6[x] * -3 + c7[x] * -3 + c8[x] * -3;
      int sum1 =
	c0[x] * -3 + c1[x] * 5 + c2[x] * 5 + c3[x] * 5 + c5[x] * -3 +
	c6[x] * -3 + c7[x] * -3 + c8[x] * -3;
      int sum2 =
	c0[x] * -3 + c1[x] * -3 + c2[x] * 5 + c3[x] * 5 + c5[x] * 5 +
	c6[x] * -3 + c7[x] * -3 + c8[x] * -3;
      int sum3 =
	c0[x] * -3 + c1[x] * -3 + c2[x] * -3 + c3[x] * 5 + c5[x] * 5 +
	c6[x] * 5 + c7[x] * -3 + c8[x] * -3;
      int sum4 =
	c0[x] * -3 + c1[x] * -3 + c2[x] * -3 + c3[x] * -3 + c5[x] * 5 +
	c6[x] * 5 + c7[x] * 5 + c8[x] * -3;
      int sum5 =
	c0[x] * -3 + c1[x] * -3 + c2[x] * -3 + c3[x] * -3 + c5[x] * -3 +
	c6[x] * 5 + c7[x] * 5 + c8[x] * 5;
      int sum6 =
	c0[x] * 5 + c1[x] * -3 + c2[x] * -3 + c3[x] * -3 + c5[x] * -3 +
	c6[x] * -3 + c7[x] * 5 + c8[x] * 5;
      int sum7 =
	c0[x] * 5 + c1[x] * 5 + c2[x] * -3 + c3[x] * -3 + c5[x] * -3 +
	c6[x] * -3 + c7[x] * -3 + c8[x] * 5;
      sum0 = ((sum0) > (sum1) ? (sum0) : (sum1));
      sum2 = ((sum2) > (sum3) ? (sum2) : (sum3));
      sum4 = ((sum4) > (sum5) ? (sum4) : (sum5));
      sum6 = ((sum6) > (sum7) ? (sum6) : (sum7));
      sum0 = ((sum0) > (sum2) ? (sum0) : (sum2));
      sum4 = ((sum4) > (sum6) ? (sum4) : (sum6));
      sum0 = ((sum0) > (sum4) ? (sum0) : (sum4));
      dst[x] =
	av_clip_uint8_c (((sum0) >= 0 ? (sum0) : (-(sum0))) * scale + delta);
} IACA_END }
