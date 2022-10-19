#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, int B, int C, const int stride2, int A, uint8_t * bsrc)
{
  for (i = 1; i < width; i++)
    {
      B = bsrc[i - stride2];
      bsrc[i] += mid_pred (A, B, (uint8_t) (A + B - C));
      C = B;
      A = bsrc[i];
    }
}
