#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int tl, int y, ptrdiff_t stride, const uint16_t * top,
    const uint16_t * left, uint16_t * dst)
{
  IACA_START for (y = 0; y < 4; y++)
    {
      int l_m_tl = left[3 - y] - tl;
      dst[0] = av_clip_uintp2_c (top[0] + l_m_tl, 12);
      dst[1] = av_clip_uintp2_c (top[1] + l_m_tl, 12);
      dst[2] = av_clip_uintp2_c (top[2] + l_m_tl, 12);
      dst[3] = av_clip_uintp2_c (top[3] + l_m_tl, 12);
      dst += stride;
}IACA_END}
