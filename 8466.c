#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;
typedef long int ptrdiff_t;

int
fn (int y, int w, uint32_t acc, ptrdiff_t linesize, int offx, int r,
    uint32_t * dst, const int s2y, const uint8_t * src, int sw, const int s1y,
    int startx, ptrdiff_t dst_linesize_32)
{
  for (int x = startx; x < startx + w; x++)
    {
      const int s1x = av_clip_c (x - r, 0, sw - 1);
      const int s2x = av_clip_c (x - (r + offx), 0, sw - 1);
      const uint8_t v1 = src[s1y * linesize + s1x];
      const uint8_t v2 = src[s2y * linesize + s2x];
      const int d = v1 - v2;
      acc += d * d;
      dst[y * dst_linesize_32 + x] = dst[(y - 1) * dst_linesize_32 + x] + acc;
}}
