#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int32_t int32_t;

int
fn (int x, int width, uint16_t * dst, int32_t * src)
{
  for (x = 0; x < width; x += 4)
    {
      dst[x] = av_clip_uintp2_c (src[x] + (1U << (10 - 1)), 10);
      dst[x + 1] = av_clip_uintp2_c (src[x + 1] + (1U << (10 - 1)), 10);
      dst[x + 2] = av_clip_uintp2_c (src[x + 2] + (1U << (10 - 1)), 10);
      dst[x + 3] = av_clip_uintp2_c (src[x + 3] + (1U << (10 - 1)), 10);
    }
}
