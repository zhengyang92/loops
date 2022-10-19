#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * srcU, int k, uint8_t * srcV, uint8_t * lut2)
{
  for (i = 0; i < k; i++)
    {
      srcU[i] = lut2[srcU[i]];
      srcV[i] = lut2[srcV[i]];
    }
}
