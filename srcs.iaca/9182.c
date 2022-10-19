#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const float postscale[64], float tmp0, float z11, float tmp2, float tmp3,
    float tmp10, float z13, float tmp5, float tmp4, float z4, float tmp1,
    float tmp6, int16_t * data, float tmp13, float tmp11, int i, float tmp7,
    float tmp12, float z2, float temp[64])
{
  for (i = 0; i < 8; i++)
    {
      tmp0 = temp[8 * 0 + i] + temp[8 * 7 + i];
      tmp7 = temp[8 * 0 + i] - temp[8 * 7 + i];
      tmp1 = temp[8 * 1 + i] + temp[8 * 6 + i];
      tmp6 = temp[8 * 1 + i] - temp[8 * 6 + i];
      tmp2 = temp[8 * 2 + i] + temp[8 * 5 + i];
      tmp5 = temp[8 * 2 + i] - temp[8 * 5 + i];
      tmp3 = temp[8 * 3 + i] + temp[8 * 4 + i];
      tmp4 = temp[8 * 3 + i] - temp[8 * 4 + i];
      tmp10 = tmp0 + tmp3;
      tmp13 = tmp0 - tmp3;
      tmp11 = tmp1 + tmp2;
      tmp12 = tmp1 - tmp2;
      data[8 * 0 + i] = lrintf (postscale[8 * 0 + i] * (tmp10 + tmp11));
      data[8 * 4 + i] = lrintf (postscale[8 * 4 + i] * (tmp10 - tmp11));
      tmp12 += tmp13;
      tmp12 *= 0.70710678118654752438;
      data[8 * 2 + i] = lrintf (postscale[8 * 2 + i] * (tmp13 + tmp12));
      data[8 * 6 + i] = lrintf (postscale[8 * 6 + i] * (tmp13 - tmp12));
      tmp4 += tmp5;
      tmp5 += tmp6;
      tmp6 += tmp7;
      z2 =
	tmp4 * (0.54119610014619698435 + 0.38268343236508977170) -
	tmp6 * 0.38268343236508977170;
      z4 =
	tmp6 * (1.30656296487637652774 - 0.38268343236508977170) +
	tmp4 * 0.38268343236508977170;
      tmp5 *= 0.70710678118654752438;
      z11 = tmp7 + tmp5;
      z13 = tmp7 - tmp5;
      data[8 * 5 + i] = lrintf (postscale[8 * 5 + i] * (z13 + z2));
      data[8 * 3 + i] = lrintf (postscale[8 * 3 + i] * (z13 - z2));
      data[8 * 1 + i] = lrintf (postscale[8 * 1 + i] * (z11 + z4));
      data[8 * 7 + i] = lrintf (postscale[8 * 7 + i] * (z11 - z4));
    }
}
