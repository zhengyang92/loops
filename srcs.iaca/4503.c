#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int v, int width, int x, float o1, uint8_t * dst, float o2, int step)
{
  for (x = 0; x < width; x += step)
    {
      dst[x] = v * o1 + dst[x] * o2;
    }
}
