#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const uint8_t * src, int width, int i, int16_t * dst)
{
  for (i = 0; i < width; i++)
    {
      dst[i] = src[4 * i] << 6 | src[4 * i] >> 2;
    }
}
