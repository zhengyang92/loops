#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t ** srcf, unsigned int rdiff, int thrb,
    unsigned int rsumdiff, int mid, unsigned int sum, int srcix, int thra,
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
