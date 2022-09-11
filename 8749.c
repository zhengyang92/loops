#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (ptrdiff_t stride, int x, uint16_t * src, const uint16_t * top, int size,
    const uint16_t * left)
{
  for (x = 0; x < size; x += 4)
    {
      src[(x) + stride * (0)] =
	av_clip_uintp2_c (left[0] + ((top[x] - top[-1]) >> 1), 10);
      src[(x + 1) + stride * (0)] =
	av_clip_uintp2_c (left[0] + ((top[x + 1] - top[-1]) >> 1), 10);
      src[(x + 2) + stride * (0)] =
	av_clip_uintp2_c (left[0] + ((top[x + 2] - top[-1]) >> 1), 10);
      src[(x + 3) + stride * (0)] =
	av_clip_uintp2_c (left[0] + ((top[x + 3] - top[-1]) >> 1), 10);
    }
}
