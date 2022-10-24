#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * b, int x, int w, const uint8_t * a)
{
  int count = 0;
  IACA_START for (x = 0; x < w; ++x)
    {
      const int diff = (int) a[x] - b[x];
      count += diff * diff;
}IACA_END}
