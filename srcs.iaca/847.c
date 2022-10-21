#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float maxval, int w, int sub, float *P, float *II, int src_ref_stride,
    float *I, const uint8_t * srcRef, const uint8_t * src, int src_stride,
    float *IP)
{
  int i = 0;
  for (int j = 0; j < w; j++)
     { IACA_START
      int x = i * w + j;
      I[x] = src[(i * src_stride + j) * sub] / maxval;
      II[x] = I[x] * I[x];
      P[x] = srcRef[(i * src_ref_stride + j) * sub] / maxval;
      IP[x] = I[x] * P[x];
} IACA_END }
