#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const *cf1, int i, double gain0, uint8_t ** dst,
    uint8_t * const *cf0, double gain1, int c, int channels)
{
  IACA_START for (c = 0; c < channels; c++)
    {
      double *d = (double *) dst[c];
      const double *s0 = (double *) cf0[c];
      const double *s1 = (double *) cf1[c];
      d[i] = s0[i] * gain0 + s1[i] * gain1;
}IACA_END}
