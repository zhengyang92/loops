#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int last, const int first, int n, int16_t * in, const int thresh,
    const uint8_t kZigzag[16])
{
  for (n = 15; n >= first; --n)
    {
      const int j = kZigzag[n];
      const int err = in[j] * in[j];
      if (err > thresh)
	{
	  last = n;
	  break;
	}
    }
}
