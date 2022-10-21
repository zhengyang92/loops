#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (uint8_t * __restrict pixels, const int16_t * block, int i,
    ptrdiff_t line_size)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      pixels[0] = av_clip_uint8_c (block[0]);
      pixels[1] = av_clip_uint8_c (block[1]);
      pixels[2] = av_clip_uint8_c (block[2]);
      pixels[3] = av_clip_uint8_c (block[3]);
      pixels[4] = av_clip_uint8_c (block[4]);
      pixels[5] = av_clip_uint8_c (block[5]);
      pixels[6] = av_clip_uint8_c (block[6]);
      pixels[7] = av_clip_uint8_c (block[7]);
      pixels += line_size;
      block += 8;
     } IACA_END
}
