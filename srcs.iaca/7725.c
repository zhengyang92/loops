#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int channel, int width, int16_t * alpha, int i)
{
  for (i = 0; i < width; i++)
    {
      channel = alpha[i];
      channel -= 256;
      channel <<= 3;
      channel *= 9400;
      channel >>= 16;
      channel = av_clip_uintp2_c (channel, 12);
      alpha[i] = channel;
    }
}
