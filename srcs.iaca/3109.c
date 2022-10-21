#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int diff, int i, const uint8_t * cbgain)
{
  int prev_diff = 0;
  for (i = 1; i < 5; i++)
     { IACA_START
      diff = cbgain[i] - cbgain[i - 1];
      if (((diff) >= 0 ? (diff) : (-(diff))) > 10)
	return -1;
      else
	if (((diff - prev_diff) >=
	     0 ? (diff - prev_diff) : (-(diff - prev_diff))) > 12)
	return -1;
      prev_diff = diff;
     } IACA_END
}
