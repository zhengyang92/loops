#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int x, const int16_t * src, int w, uint8_t * dst)
{
  int m = 0;
  IACA_START for (x = 0; x < w; x++)
    {
      int t = src[x] + 128;
      dst[x] = t;
      m |= t;
}IACA_END}
