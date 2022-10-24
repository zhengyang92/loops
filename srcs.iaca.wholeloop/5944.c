#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int imax, unsigned long hmax, unsigned long hist[256])
{
  IACA_START for (i = 0; i < 256; ++i)
    if (hist[i] > hmax)
      {
	imax = i;
	hmax = hist[i];
      }
}
