#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __uint32_t uint32_t;

int
fn (ptrdiff_t stride, uint32_t * sq, int h, uint8_t * pix1, uint8_t * pix2,
    int s)
{
  int i = 0;
  for (i = 0; i < h; i++)
     { IACA_START
      s += sq[pix1[0] - pix2[0]];
      s += sq[pix1[1] - pix2[1]];
      s += sq[pix1[2] - pix2[2]];
      s += sq[pix1[3] - pix2[3]];
      pix1 += stride;
      pix2 += stride;
     } IACA_END
}
