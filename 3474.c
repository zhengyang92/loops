#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, int dc, int i, uint8_t * dest)
{
  for (i = 0; i < 4; i++)
    {
      dest[0] = av_clip_uint8_c (dest[0] + dc);
      dest[1] = av_clip_uint8_c (dest[1] + dc);
      dest[2] = av_clip_uint8_c (dest[2] + dc);
      dest[3] = av_clip_uint8_c (dest[3] + dc);
      dest += stride;
    }
}
