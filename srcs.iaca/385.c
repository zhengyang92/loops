#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t ** srcf, int thrb, unsigned int ldiff, int mid,
    const float *weights, float sum, int thra, const int srcx, int l,
    int srcjx, unsigned int lsumdiff)
{
  int x = 0;
  float wsum = 1.f;
  for (int j = mid - 1; j >= 0; j--)
     { IACA_START
      srcjx = srcf[j][x];
      ldiff = ((srcx - srcjx) >= 0 ? (srcx - srcjx) : (-(srcx - srcjx)));
      lsumdiff += ldiff;
      if (ldiff > thra || lsumdiff > thrb)
	break;
      l++;
      sum += srcjx * weights[j];
      wsum += weights[j];
     } IACA_END
}
