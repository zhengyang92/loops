#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int x, float f, const int max, uint16_t * dst,
    const uint16_t * src)
{
  for (x = 0; x < w; x++)
    {
      dst[x] = av_clip_c (src[x] * f, 0, max);
    }
}
