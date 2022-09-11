#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int dc, uint8_t * dst, int i)
{
  for (i = 0; i < 4; i++)
    {
      dst[0] = av_clip_uint8_c (dst[0] + dc);
      dst[1] = av_clip_uint8_c (dst[1] + dc);
      dst[2] = av_clip_uint8_c (dst[2] + dc);
      dst[3] = av_clip_uint8_c (dst[3] + dc);
      dst += stride;
    }
}
