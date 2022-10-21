#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int x, const int16_t * src, uint8_t * dst, int w)
{
  int m = 0;
  for (x = 0; x < w; x++)
     { IACA_START
      int t = src[x] + 128;
      dst[x] = t;
      m |= t;
} IACA_END }
