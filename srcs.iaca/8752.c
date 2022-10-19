#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int i, uint16_t l, uint16_t lt, const uint16_t * src2,
    const uint16_t * src1, unsigned int mask, uint16_t * dst)
{
  for (i = 0; i < w; i++)
    {
      const int pred = mid_pred (l, src1[i], (l + src1[i] - lt) & mask);
      lt = src1[i];
      l = src2[i];
      dst[i] = (l - pred) & mask;
}}
