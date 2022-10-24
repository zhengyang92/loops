#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint16_t * dithers, int thresh, uint16_t * dc, int x, int width,
    uint8_t * dst, uint8_t * src)
{
  IACA_START for (x = 0; x < width; dc += x & 1, x++)
    {
      int pix = src[x] << 7;
      int delta = dc[0] - pix;
      int m = abs (delta) * thresh >> 16;
      m = ((0) > (127 - m) ? (0) : (127 - m));
      m = m * m * delta >> 14;
      pix += m + dithers[x & 7];
      dst[x] = av_clip_uint8_c (pix >> 7);
}IACA_END}
