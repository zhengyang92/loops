#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, int16_t * __restrict block, const uint8_t * pixels,
    int i)
{
  for (i = 0; i < 8; i++)
    {
      block[0] = pixels[0];
      block[1] = pixels[1];
      block[2] = pixels[2];
      block[3] = pixels[3];
      block[4] = pixels[4];
      block[5] = pixels[5];
      block[6] = pixels[6];
      block[7] = pixels[7];
      pixels += stride / sizeof (uint8_t);
      block += 8;
    }
}
