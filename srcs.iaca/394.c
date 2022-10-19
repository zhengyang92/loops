#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int rdiff, int thrb, unsigned int sum, int mid,
    unsigned int rsumdiff, int srcix, int thra, const uint16_t ** srcf,
    const int srcx, int size)
{
  int r = 0;
  int x = 0;
  for (int i = mid + 1; i < size; i++)
    {
      srcix = srcf[i][x];
      rdiff = ((srcx - srcix) >= 0 ? (srcx - srcix) : (-(srcx - srcix)));
      rsumdiff += rdiff;
      if (rdiff > thra || rsumdiff > thrb)
	break;
      r++;
      sum += srcix;
    }
}
