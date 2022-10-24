#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float FLOAT;
typedef __int16_t int16_t;

int
fn (FLOAT tmp3, FLOAT tmp7, FLOAT tmp10, int i, FLOAT tmp5, int16_t * data,
    FLOAT tmp13, FLOAT tmp2, FLOAT tmp1, FLOAT temp[64], FLOAT tmp0,
    FLOAT tmp11, const FLOAT postscale[64], FLOAT tmp6, FLOAT tmp12,
    FLOAT tmp4)
{
  IACA_START for (i = 0; i < 8; i++)
    {
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
      tmp12 *= 0.70710678118654752440;
      data[8 * 2 + i] = lrintf (postscale[8 * 2 + i] * (tmp13 + tmp12));
      data[8 * 6 + i] = lrintf (postscale[8 * 6 + i] * (tmp13 - tmp12));
      tmp10 = tmp4 + tmp7;
      tmp11 = tmp5 + tmp6;
      tmp12 = tmp5 - tmp6;
      tmp13 = tmp4 - tmp7;
      data[8 * 1 + i] = lrintf (postscale[8 * 0 + i] * (tmp10 + tmp11));
      data[8 * 5 + i] = lrintf (postscale[8 * 4 + i] * (tmp10 - tmp11));
      tmp12 += tmp13;
      tmp12 *= 0.70710678118654752440;
      data[8 * 3 + i] = lrintf (postscale[8 * 2 + i] * (tmp13 + tmp12));
      data[8 * 7 + i] = lrintf (postscale[8 * 6 + i] * (tmp13 - tmp12));
     } IACA_END
}
