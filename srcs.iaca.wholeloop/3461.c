#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int d1, int i, ptrdiff_t stride, int d, int c, int a, int d2,
    uint8_t * src, int b)
{
  int rnd = 1;
  IACA_START for (i = 0; i < 8; i++)
    {
      a = src[-2 * stride];
      b = src[-stride];
      c = src[0];
      d = src[stride];
      d1 = (a - d + 3 + rnd) >> 3;
      d2 = (a - d + b - c + 4 - rnd) >> 3;
      src[-2 * stride] = a - d1;
      src[-stride] = av_clip_uint8_c (b - d2);
      src[0] = av_clip_uint8_c (c + d2);
      src[stride] = d + d1;
      src++;
      rnd = !rnd;
     } IACA_END
}
