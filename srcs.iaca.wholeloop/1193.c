#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, const int mid, int x, const int factor, uint16_t * ydst,
    uint16_t * vdst, uint16_t * udst)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int c = factor * x / w;
      ydst[x] = c;
      udst[x] = mid;
      vdst[x] = mid;
}IACA_END}
