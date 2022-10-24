#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __int16_t int16_t;

int
fn (unsigned int half_pi, unsigned int s, unsigned int step, int16_t * sin,
    unsigned int k, unsigned int n2, uint64_t unit2, unsigned int i,
    unsigned int c, unsigned int new_k)
{
  IACA_START for (i = 0; i < half_pi / 2; i += step)
    {
      s = sin[i] + sin[i + step];
      c = sin[half_pi - i] + sin[half_pi - i - step];
      n2 = s * s + c * c;
      while (1)
	{
	  new_k = (k + unit2 / ((uint64_t) k * n2) + 1) >> 1;
	  if (k == new_k)
	    break;
	  k = new_k;
	}
      sin[i + step / 2] = (k * s + 0x7FFF) >> 16;
      sin[half_pi - i - step / 2] = (k * c + 0x8000) >> 16;
     } IACA_END
}
