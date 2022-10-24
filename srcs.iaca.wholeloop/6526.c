#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, int h, uint8_t * pix1, uint8_t * pix2, int s)
{
  int i = 0;
  IACA_START for (i = 0; i < h; i++)
    {
      s += abs (pix1[0] - pix2[0]);
      s += abs (pix1[1] - pix2[1]);
      s += abs (pix1[2] - pix2[2]);
      s += abs (pix1[3] - pix2[3]);
      s += abs (pix1[4] - pix2[4]);
      s += abs (pix1[5] - pix2[5]);
      s += abs (pix1[6] - pix2[6]);
      s += abs (pix1[7] - pix2[7]);
      pix1 += stride;
      pix2 += stride;
     } IACA_END
}
