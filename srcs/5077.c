#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (ptrdiff_t stride, int h, uint8_t * pix1, uint8_t * pix3, uint8_t * pix2,
    int s)
{
  int i = 0;
  for (i = 0; i < h; i++)
    {
      s += abs (pix1[0] - (((pix2[0]) + (pix3[0]) + 1) >> 1));
      s += abs (pix1[1] - (((pix2[1]) + (pix3[1]) + 1) >> 1));
      s += abs (pix1[2] - (((pix2[2]) + (pix3[2]) + 1) >> 1));
      s += abs (pix1[3] - (((pix2[3]) + (pix3[3]) + 1) >> 1));
      s += abs (pix1[4] - (((pix2[4]) + (pix3[4]) + 1) >> 1));
      s += abs (pix1[5] - (((pix2[5]) + (pix3[5]) + 1) >> 1));
      s += abs (pix1[6] - (((pix2[6]) + (pix3[6]) + 1) >> 1));
      s += abs (pix1[7] - (((pix2[7]) + (pix3[7]) + 1) >> 1));
      s += abs (pix1[8] - (((pix2[8]) + (pix3[8]) + 1) >> 1));
      s += abs (pix1[9] - (((pix2[9]) + (pix3[9]) + 1) >> 1));
      s += abs (pix1[10] - (((pix2[10]) + (pix3[10]) + 1) >> 1));
      s += abs (pix1[11] - (((pix2[11]) + (pix3[11]) + 1) >> 1));
      s += abs (pix1[12] - (((pix2[12]) + (pix3[12]) + 1) >> 1));
      s += abs (pix1[13] - (((pix2[13]) + (pix3[13]) + 1) >> 1));
      s += abs (pix1[14] - (((pix2[14]) + (pix3[14]) + 1) >> 1));
      s += abs (pix1[15] - (((pix2[15]) + (pix3[15]) + 1) >> 1));
      pix1 += stride;
      pix2 += stride;
      pix3 += stride;
    }
}
