#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * block, int i, ptrdiff_t line_size, uint8_t * dest)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      dest[0] = av_clip_uint8_c (block[0]);
      dest[1] = av_clip_uint8_c (block[1]);
      dest[2] = av_clip_uint8_c (block[2]);
      dest[3] = av_clip_uint8_c (block[3]);
      dest[4] = av_clip_uint8_c (block[4]);
      dest[5] = av_clip_uint8_c (block[5]);
      dest[6] = av_clip_uint8_c (block[6]);
      dest[7] = av_clip_uint8_c (block[7]);
      dest += line_size;
      block += 8;
     } IACA_END
}
