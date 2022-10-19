#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint16_t * segment, int k, const int t, int sum, uint8_t * dst)
{
  int j = 0;
  int b = 0;
  for (b = 0; b < (1 << ((8 + 1) / 2)); b++)
    {
      sum += segment[b];
      if (sum > t)
	{
	  dst[j] = (1 << ((8 + 1) / 2)) * k + b;
	  break;
	}
    }
}
