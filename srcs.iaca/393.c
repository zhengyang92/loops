#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int thrb, unsigned int ldiff, unsigned int sum, int mid, int thra,
    const uint16_t ** srcf, const int srcx, int l, int srcjx,
    unsigned int lsumdiff)
{
  int x = 0;
  for (int j = mid - 1; j >= 0; j--)
    {
      srcjx = srcf[j][x];
      ldiff = ((srcx - srcjx) >= 0 ? (srcx - srcjx) : (-(srcx - srcjx)));
      lsumdiff += ldiff;
      if (ldiff > thra || lsumdiff > thrb)
	break;
      l++;
      sum += srcjx;
    }
}
