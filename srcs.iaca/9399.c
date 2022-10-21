#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int h, uint8_t * pix1, uint8_t * pix2, int s)
{
  int i = 0;
  for (i = 0; i < h; i++)
     { IACA_START
      s += abs (pix1[0] - pix2[0]);
      s += abs (pix1[1] - pix2[1]);
      s += abs (pix1[2] - pix2[2]);
      s += abs (pix1[3] - pix2[3]);
      s += abs (pix1[4] - pix2[4]);
      s += abs (pix1[5] - pix2[5]);
      s += abs (pix1[6] - pix2[6]);
      s += abs (pix1[7] - pix2[7]);
      s += abs (pix1[8] - pix2[8]);
      s += abs (pix1[9] - pix2[9]);
      s += abs (pix1[10] - pix2[10]);
      s += abs (pix1[11] - pix2[11]);
      s += abs (pix1[12] - pix2[12]);
      s += abs (pix1[13] - pix2[13]);
      s += abs (pix1[14] - pix2[14]);
      s += abs (pix1[15] - pix2[15]);
      pix1 += stride;
      pix2 += stride;
     } IACA_END
}
