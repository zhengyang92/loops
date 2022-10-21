#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (uint8_t * __restrict pixels, const int16_t * block, int line_size, int i)
{
  for (i = 0; i < 2; i++)
     { IACA_START
      pixels[0] = av_clip_uint8_c (block[0]);
      pixels[1] = av_clip_uint8_c (block[1]);
      pixels += line_size;
      block += 8;
     } IACA_END
}
