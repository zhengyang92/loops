#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (float tmp10, const float postscale[64], float tmp4, float tmp5,
    float tmp7, float tmp1, float tmp6, int i, int16_t * data, float tmp12,
    float tmp3, float tmp0, float temp[64], float tmp2, float tmp13,
    float tmp11)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      tmp0 = temp[8 * 0 + i] + temp[8 * 1 + i];
      tmp1 = temp[8 * 2 + i] + temp[8 * 3 + i];
      tmp2 = temp[8 * 4 + i] + temp[8 * 5 + i];
      tmp3 = temp[8 * 6 + i] + temp[8 * 7 + i];
      tmp4 = temp[8 * 0 + i] - temp[8 * 1 + i];
      tmp5 = temp[8 * 2 + i] - temp[8 * 3 + i];
      tmp6 = temp[8 * 4 + i] - temp[8 * 5 + i];
      tmp7 = temp[8 * 6 + i] - temp[8 * 7 + i];
      tmp10 = tmp0 + tmp3;
      tmp11 = tmp1 + tmp2;
      tmp12 = tmp1 - tmp2;
      tmp13 = tmp0 - tmp3;
      data[8 * 0 + i] = lrintf (postscale[8 * 0 + i] * (tmp10 + tmp11));
      data[8 * 4 + i] = lrintf (postscale[8 * 4 + i] * (tmp10 - tmp11));
      tmp12 += tmp13;
      tmp12 *= 0.70710678118654752438;
      data[8 * 2 + i] = lrintf (postscale[8 * 2 + i] * (tmp13 + tmp12));
      data[8 * 6 + i] = lrintf (postscale[8 * 6 + i] * (tmp13 - tmp12));
      tmp10 = tmp4 + tmp7;
      tmp11 = tmp5 + tmp6;
      tmp12 = tmp5 - tmp6;
      tmp13 = tmp4 - tmp7;
      data[8 * 1 + i] = lrintf (postscale[8 * 0 + i] * (tmp10 + tmp11));
      data[8 * 5 + i] = lrintf (postscale[8 * 4 + i] * (tmp10 - tmp11));
      tmp12 += tmp13;
      tmp12 *= 0.70710678118654752438;
      data[8 * 3 + i] = lrintf (postscale[8 * 2 + i] * (tmp13 + tmp12));
      data[8 * 7 + i] = lrintf (postscale[8 * 6 + i] * (tmp13 - tmp12));
     } IACA_END
}
