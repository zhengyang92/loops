#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int rdiff, int thrb, unsigned int ldiff, unsigned int rsumdiff,
    unsigned int sum, int mid, int srcix, int thra, const uint16_t ** srcf,
    const int srcx, int size, int l, int srcjx, unsigned int lsumdiff)
{
  int r = 0;
  int x = 0;
  for (int j = mid - 1, i = mid + 1; j >= 0 && i < size; j--, i++)
    {
      srcjx = srcf[j][x];
      ldiff = ((srcx - srcjx) >= 0 ? (srcx - srcjx) : (-(srcx - srcjx)));
      lsumdiff += ldiff;
      if (ldiff > thra || lsumdiff > thrb)
	break;
      l++;
      sum += srcjx;
      srcix = srcf[i][x];
      rdiff = ((srcx - srcix) >= 0 ? (srcx - srcix) : (-(srcx - srcix)));
      rsumdiff += rdiff;
      if (rdiff > thra || rsumdiff > thrb)
	break;
      r++;
      sum += srcix;
    }
}
