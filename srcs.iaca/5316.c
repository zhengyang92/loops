#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (const uint8_t * block, int mu[3], int y, ptrdiff_t stride, int x,
    int cov[6])
{
  for (x = 0; x < 4; x++)
    {
      int r = block[x * 4 + stride * y + 0] - mu[0];
      int g = block[x * 4 + stride * y + 1] - mu[1];
      int b = block[x * 4 + stride * y + 2] - mu[2];
      cov[0] += r * r;
      cov[1] += r * g;
      cov[2] += r * b;
      cov[3] += g * g;
      cov[4] += g * b;
      cov[5] += b * b;
}}
