#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int s_1, int f0, int shift, int i, int16_t * out0, int d, int t,
    const uint8_t * in, int f1, int s, int j, int s_2)
{
  for (j = 0; j < 28; j++)
    {
      d = in[16 + i + j * 4];
      t = sign_extend (d, 4);
      s = (t << shift) + ((s_1 * f0 + s_2 * f1 + 32) >> 6);
      s_2 = s_1;
      s_1 = av_clip_int16_c (s);
      out0[j] = s_1;
    }
}
