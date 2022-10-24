#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int src_size, uint8_t * dst, const uint8_t * src, int i)
{
  IACA_START for (i = 0; i < src_size; i += 4)
    {
      dst[i + 0] = src[i + 3];
      dst[i + 1] = src[i + 2];
      dst[i + 2] = src[i + 1];
      dst[i + 3] = src[i + 0];
     } IACA_END
}
