#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const *cf1, int i, double gain0, uint8_t ** dst,
    uint8_t * const *cf0, double gain1, int c, int channels)
{
  for (c = 0; c < channels; c++)
     { IACA_START
      float *d = (float *) dst[c];
      const float *s0 = (float *) cf0[c];
      const float *s1 = (float *) cf1[c];
      d[i] = s0[i] * gain0 + s1[i] * gain1;
} IACA_END }
