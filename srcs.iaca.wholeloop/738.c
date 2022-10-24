#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * c2, float delta, const uint16_t * c1, int width,
    const uint16_t * c8, const uint16_t * c0, const uint16_t * c6,
    float scale, int peak, const uint16_t * c7, int x, const uint16_t * c5,
    uint16_t * dst, const uint16_t * c3)
{
  IACA_START for (x = 0; x < width; x++)
    {
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
	av_clip_c (((sum0) >= 0 ? (sum0) : (-(sum0))) * scale + delta, 0,
		   peak);
}IACA_END}
