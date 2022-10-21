#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * ccoarse, const uint16_t * srcp, int width, const int radiusV,
    uint16_t * cfine)
{
  for (int i = 0; i < width; i++)
     { IACA_START
      cfine[((1 << ((12 + 1) / 2)) *
	     ((width) * ((srcp[i]) >> ((12 + 1) / 2)) + (i)) +
	     ((srcp[i]) & ((1 << ((12 + 1) / 2)) - 1)))] += radiusV + 1;
      ccoarse[((1 << ((12 + 1) / 2)) * (i) +
	       ((srcp[i]) >> ((12 + 1) / 2)))] += radiusV + 1;
} IACA_END }
