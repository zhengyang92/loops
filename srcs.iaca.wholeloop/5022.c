#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int i, uint16_t l, uint16_t lt, unsigned int mask,
    const uint16_t * src1, const uint16_t * src2, uint16_t * dst)
{
  IACA_START for (i = 0; i < w; i++)
    {
      const int pred = mid_pred (l, src1[i], (l + src1[i] - lt) & mask);
      lt = src1[i];
      l = src2[i];
      dst[i] = (l - pred) & mask;
}IACA_END}
