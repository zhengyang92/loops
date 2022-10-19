#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * src, uint8_t * dst, int i, int stride)
{
  for (i = 0; i < 4; i++)
    {
      dst[0] += src[0];
      dst[1] += src[1];
      dst[2] += src[2];
      dst[3] += src[3];
      dst += stride;
      src += 4;
    }
}
