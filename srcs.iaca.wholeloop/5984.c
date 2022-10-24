#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (double p, double newocc[256], double occ[256], int m,
    const uint8_t * one_state)
{
  IACA_START for (m = 1; m < 256; m++)
    if (occ[m])
      {
	newocc[one_state[m]] += occ[m] * p;
	newocc[256 - one_state[256 - m]] += occ[m] * (1 - p);
      }
  IACA_END
}
