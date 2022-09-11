#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint16_t * dst, int32_t * src, int stride)
{
  for (i = 0; i < 8; i++)
    {
      dst[0] += src[0];
      dst[1] += src[1];
      dst[2] += src[2];
      dst[3] += src[3];
      dst[4] += src[4];
      dst[5] += src[5];
      dst[6] += src[6];
      dst[7] += src[7];
      dst += stride;
      src += 8;
    }
}
