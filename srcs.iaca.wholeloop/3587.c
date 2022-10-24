#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int tl, int y, ptrdiff_t stride, const uint8_t * left,
    const uint8_t * top, uint8_t * dst)
{
  IACA_START for (y = 0; y < 4; y++)
    {
      int l_m_tl = left[3 - y] - tl;
      dst[0] = av_clip_uint8_c (top[0] + l_m_tl);
      dst[1] = av_clip_uint8_c (top[1] + l_m_tl);
      dst[2] = av_clip_uint8_c (top[2] + l_m_tl);
      dst[3] = av_clip_uint8_c (top[3] + l_m_tl);
      dst += stride;
}IACA_END}
