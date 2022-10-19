#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int tl, int y, ptrdiff_t stride, const uint16_t * top,
    const uint16_t * left, uint16_t * dst)
{
  for (y = 0; y < 16; y++)
    {
      int l_m_tl = left[15 - y] - tl;
      dst[0] = av_clip_uintp2_c (top[0] + l_m_tl, 10);
      dst[1] = av_clip_uintp2_c (top[1] + l_m_tl, 10);
      dst[2] = av_clip_uintp2_c (top[2] + l_m_tl, 10);
      dst[3] = av_clip_uintp2_c (top[3] + l_m_tl, 10);
      dst[4] = av_clip_uintp2_c (top[4] + l_m_tl, 10);
      dst[5] = av_clip_uintp2_c (top[5] + l_m_tl, 10);
      dst[6] = av_clip_uintp2_c (top[6] + l_m_tl, 10);
      dst[7] = av_clip_uintp2_c (top[7] + l_m_tl, 10);
      dst[8] = av_clip_uintp2_c (top[8] + l_m_tl, 10);
      dst[9] = av_clip_uintp2_c (top[9] + l_m_tl, 10);
      dst[10] = av_clip_uintp2_c (top[10] + l_m_tl, 10);
      dst[11] = av_clip_uintp2_c (top[11] + l_m_tl, 10);
      dst[12] = av_clip_uintp2_c (top[12] + l_m_tl, 10);
      dst[13] = av_clip_uintp2_c (top[13] + l_m_tl, 10);
      dst[14] = av_clip_uintp2_c (top[14] + l_m_tl, 10);
      dst[15] = av_clip_uintp2_c (top[15] + l_m_tl, 10);
      dst += stride;
}}
