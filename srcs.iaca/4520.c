#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, const int mid, int x, uint16_t * ydst, const int factor,
    uint16_t * vdst, uint16_t * udst)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int c = factor * x / w;
      ydst[x] = mid;
      udst[x] = c;
      vdst[x] = mid;
} IACA_END }
