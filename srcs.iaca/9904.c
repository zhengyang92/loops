#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * const clip, int x, int size, const uint8_t * top,
    uint8_t * dst)
{
  for (x = 0; x < size; ++x)
    {
      dst[x] = clip[top[x]];
    }
}
