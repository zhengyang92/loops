#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint16_t * src, const int32_t * block, uint16_t pix[8], int stride)
{
  for (i = 0; i < 8; i++)
    {
      uint16_t v = pix[i];
      src[0 * stride] = v += block[0];
      src[1 * stride] = v += block[8];
      src[2 * stride] = v += block[16];
      src[3 * stride] = v += block[24];
      src[4 * stride] = v += block[32];
      src[5 * stride] = v += block[40];
      src[6 * stride] = v += block[48];
      src[7 * stride] = v + block[56];
      src++;
      block++;
    }
}
