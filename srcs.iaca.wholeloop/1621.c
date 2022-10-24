#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int s_1, int f0, int i, int16_t * out0, int d, int t, const uint8_t * in,
    int s, int f1, int shift, int j, int s_2)
{
  IACA_START for (j = 0; j < 28; j++)
    {
      d = in[16 + i + j * 4];
      t = sign_extend (d, 4);
      s = t * (1 << shift) + ((s_1 * f0 + s_2 * f1 + 32) >> 6);
      s_2 = s_1;
      s_1 = av_clip_int16_c (s);
      out0[j] = s_1;
     } IACA_END
}
