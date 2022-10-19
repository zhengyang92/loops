#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, uint8_t * dst, int i, int src_size)
{
  for (i = 0; i < src_size; i += 4)
    {
      dst[i + 0] = src[i + 3];
      dst[i + 1] = src[i + 2];
      dst[i + 2] = src[i + 1];
      dst[i + 3] = src[i + 0];
    }
}
