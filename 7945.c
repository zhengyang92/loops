#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, const uint8_t * left, int x, int size,
    const uint8_t * top, uint8_t * src)
{
  for (x = 0; x < size; x += 4)
    {
      src[(x) + stride * (0)] =
	av_clip_uint8_c (left[0] + ((top[x] - top[-1]) >> 1));
      src[(x + 1) + stride * (0)] =
	av_clip_uint8_c (left[0] + ((top[x + 1] - top[-1]) >> 1));
      src[(x + 2) + stride * (0)] =
	av_clip_uint8_c (left[0] + ((top[x + 2] - top[-1]) >> 1));
      src[(x + 3) + stride * (0)] =
	av_clip_uint8_c (left[0] + ((top[x + 3] - top[-1]) >> 1));
    }
}
