#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int rdiff, int thrb, unsigned int rsumdiff, int mid,
    const float *weights, int srcix, float sum, int thra,
    const uint16_t ** srcf, const int srcx, int size)
{
  int r = 0;
  int x = 0;
  float wsum = 1.f;
  for (int i = mid + 1; i < size; i++)
    {
      srcix = srcf[i][x];
      rdiff = ((srcx - srcix) >= 0 ? (srcx - srcix) : (-(srcx - srcix)));
      rsumdiff += rdiff;
      if (rdiff > thra || rsumdiff > thrb)
	break;
      r++;
      sum += srcix * weights[i];
      wsum += weights[i];
    }
}
