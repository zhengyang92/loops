#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * cfine, int width, uint16_t * ccoarse, const uint16_t * p)
{
  for (int j = 0; j < width; j++)
     { IACA_START
      cfine[((1 << ((9 + 1) / 2)) *
	     ((width) * ((p[j]) >> ((9 + 1) / 2)) + (j)) +
	     ((p[j]) & ((1 << ((9 + 1) / 2)) - 1)))]++;
      ccoarse[((1 << ((9 + 1) / 2)) * (j) + ((p[j]) >> ((9 + 1) / 2)))]++;
} IACA_END }
