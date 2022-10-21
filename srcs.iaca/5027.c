#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * __restrict pixels, const int16_t * block, int line_size, int i)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      pixels[0] = av_clip_uint8_c (pixels[0] + block[0]);
      pixels[1] = av_clip_uint8_c (pixels[1] + block[1]);
      pixels[2] = av_clip_uint8_c (pixels[2] + block[2]);
      pixels[3] = av_clip_uint8_c (pixels[3] + block[3]);
      pixels += line_size;
      block += 8;
     } IACA_END
}
