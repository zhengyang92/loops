#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const int16_t * block, uint8_t * __restrict pixels, int line_size, int i)
{
  for (i = 0; i < 2; i++)
    {
      pixels[0] = av_clip_uint8_c (block[0]);
      pixels[1] = av_clip_uint8_c (block[1]);
      pixels += line_size;
      block += 8;
    }
}
