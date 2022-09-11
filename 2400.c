#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int V, int H, uint16_t * src, int a, int j, int stride)
{
  for (j = 8; j > 0; --j)
    {
      int b = a;
      a += V;
      src[0] = av_clip_uintp2_c ((b) >> 5, 12);
      src[1] = av_clip_uintp2_c ((b + H) >> 5, 12);
      src[2] = av_clip_uintp2_c ((b + 2 * H) >> 5, 12);
      src[3] = av_clip_uintp2_c ((b + 3 * H) >> 5, 12);
      src[4] = av_clip_uintp2_c ((b + 4 * H) >> 5, 12);
      src[5] = av_clip_uintp2_c ((b + 5 * H) >> 5, 12);
      src[6] = av_clip_uintp2_c ((b + 6 * H) >> 5, 12);
      src[7] = av_clip_uintp2_c ((b + 7 * H) >> 5, 12);
      src += stride;
}}
