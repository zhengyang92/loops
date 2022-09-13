#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int tl, int y, ptrdiff_t stride, const uint8_t * left,
    const uint8_t * top, uint8_t * dst)
{
  for (y = 0; y < 32; y++)
    {
      int l_m_tl = left[31 - y] - tl;
      dst[0] = av_clip_uint8_c (top[0] + l_m_tl);
      dst[1] = av_clip_uint8_c (top[1] + l_m_tl);
      dst[2] = av_clip_uint8_c (top[2] + l_m_tl);
      dst[3] = av_clip_uint8_c (top[3] + l_m_tl);
      dst[4] = av_clip_uint8_c (top[4] + l_m_tl);
      dst[5] = av_clip_uint8_c (top[5] + l_m_tl);
      dst[6] = av_clip_uint8_c (top[6] + l_m_tl);
      dst[7] = av_clip_uint8_c (top[7] + l_m_tl);
      dst[8] = av_clip_uint8_c (top[8] + l_m_tl);
      dst[9] = av_clip_uint8_c (top[9] + l_m_tl);
      dst[10] = av_clip_uint8_c (top[10] + l_m_tl);
      dst[11] = av_clip_uint8_c (top[11] + l_m_tl);
      dst[12] = av_clip_uint8_c (top[12] + l_m_tl);
      dst[13] = av_clip_uint8_c (top[13] + l_m_tl);
      dst[14] = av_clip_uint8_c (top[14] + l_m_tl);
      dst[15] = av_clip_uint8_c (top[15] + l_m_tl);
      dst[16] = av_clip_uint8_c (top[16] + l_m_tl);
      dst[17] = av_clip_uint8_c (top[17] + l_m_tl);
      dst[18] = av_clip_uint8_c (top[18] + l_m_tl);
      dst[19] = av_clip_uint8_c (top[19] + l_m_tl);
      dst[20] = av_clip_uint8_c (top[20] + l_m_tl);
      dst[21] = av_clip_uint8_c (top[21] + l_m_tl);
      dst[22] = av_clip_uint8_c (top[22] + l_m_tl);
      dst[23] = av_clip_uint8_c (top[23] + l_m_tl);
      dst[24] = av_clip_uint8_c (top[24] + l_m_tl);
      dst[25] = av_clip_uint8_c (top[25] + l_m_tl);
      dst[26] = av_clip_uint8_c (top[26] + l_m_tl);
      dst[27] = av_clip_uint8_c (top[27] + l_m_tl);
      dst[28] = av_clip_uint8_c (top[28] + l_m_tl);
      dst[29] = av_clip_uint8_c (top[29] + l_m_tl);
      dst[30] = av_clip_uint8_c (top[30] + l_m_tl);
      dst[31] = av_clip_uint8_c (top[31] + l_m_tl);
      dst += stride;
}}
