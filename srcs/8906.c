#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int tl, int y, ptrdiff_t stride, const uint16_t * top,
    const uint16_t * left, uint16_t * dst)
{
  for (y = 0; y < 8; y++)
    {
      int l_m_tl = left[7 - y] - tl;
      dst[0] = av_clip_uintp2_c (top[0] + l_m_tl, 10);
      dst[1] = av_clip_uintp2_c (top[1] + l_m_tl, 10);
      dst[2] = av_clip_uintp2_c (top[2] + l_m_tl, 10);
      dst[3] = av_clip_uintp2_c (top[3] + l_m_tl, 10);
      dst[4] = av_clip_uintp2_c (top[4] + l_m_tl, 10);
      dst[5] = av_clip_uintp2_c (top[5] + l_m_tl, 10);
      dst[6] = av_clip_uintp2_c (top[6] + l_m_tl, 10);
      dst[7] = av_clip_uintp2_c (top[7] + l_m_tl, 10);
      dst += stride;
}}
