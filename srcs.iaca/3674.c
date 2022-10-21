#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (int16_t * block, int i, ptrdiff_t line_size, uint8_t * dest)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      dest[0] = av_clip_uint8_c (dest[0] + block[0]);
      dest[1] = av_clip_uint8_c (dest[1] + block[1]);
      dest[2] = av_clip_uint8_c (dest[2] + block[2]);
      dest[3] = av_clip_uint8_c (dest[3] + block[3]);
      dest[4] = av_clip_uint8_c (dest[4] + block[4]);
      dest[5] = av_clip_uint8_c (dest[5] + block[5]);
      dest[6] = av_clip_uint8_c (dest[6] + block[6]);
      dest[7] = av_clip_uint8_c (dest[7] + block[7]);
      dest += line_size;
      block += 8;
     } IACA_END
}
