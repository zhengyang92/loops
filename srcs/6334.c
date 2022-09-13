#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int x, uint8_t * dst, int16_t * res, int size)
{
  for (x = 0; x < size; x++)
    {
      dst[x] = av_clip_uint8_c (dst[x] + *res);
      res++;
    }
}
