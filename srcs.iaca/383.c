#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t ** srcf, unsigned int rdiff, int thrb, unsigned int ldiff,
    unsigned int rsumdiff, int mid, const float *weights, int srcix,
    float sum, int thra, const int srcx, int size, int l, int srcjx,
    unsigned int lsumdiff)
{
  int r = 0;
  float wsum = 1.f;
  int x = 0;
  for (int j = mid - 1, i = mid + 1; j >= 0 && i < size; j--, i++)
    {
      srcjx = srcf[j][x];
      ldiff = ((srcx - srcjx) >= 0 ? (srcx - srcjx) : (-(srcx - srcjx)));
      lsumdiff += ldiff;
      if (ldiff > thra || lsumdiff > thrb)
	break;
      l++;
      sum += srcjx * weights[j];
      wsum += weights[j];
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
