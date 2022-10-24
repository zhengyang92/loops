#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int h, uint8_t * pix1, uint8_t * pix3, uint8_t * pix2,
    int s)
{
  int i = 0;
  IACA_START for (i = 0; i < h; i++)
    {
      s += abs (pix1[0] - ((pix2[0] + pix3[0] + 1) >> 1));
      s += abs (pix1[1] - ((pix2[1] + pix3[1] + 1) >> 1));
      s += abs (pix1[2] - ((pix2[2] + pix3[2] + 1) >> 1));
      s += abs (pix1[3] - ((pix2[3] + pix3[3] + 1) >> 1));
      s += abs (pix1[4] - ((pix2[4] + pix3[4] + 1) >> 1));
      s += abs (pix1[5] - ((pix2[5] + pix3[5] + 1) >> 1));
      s += abs (pix1[6] - ((pix2[6] + pix3[6] + 1) >> 1));
      s += abs (pix1[7] - ((pix2[7] + pix3[7] + 1) >> 1));
      pix1 += stride;
      pix2 += stride;
      pix3 += stride;
     } IACA_END
}
