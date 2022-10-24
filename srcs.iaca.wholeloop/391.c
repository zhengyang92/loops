#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t ** srcf, int thrb, unsigned int ldiff, unsigned int sum,
    int mid, int thra, const int srcx, int l, int srcjx,
    unsigned int lsumdiff)
{
  int x = 0;
  IACA_START for (int j = mid - 1; j >= 0; j--)
    {
      srcjx = srcf[j][x];
      ldiff = ((srcx - srcjx) >= 0 ? (srcx - srcjx) : (-(srcx - srcjx)));
      lsumdiff += ldiff;
      if (ldiff > thra || lsumdiff > thrb)
	break;
      l++;
      sum += srcjx;
     } IACA_END
}
