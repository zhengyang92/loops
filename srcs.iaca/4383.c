#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t * cfine, int width, uint16_t * ccoarse, const uint8_t * srcp)
{
  for (int j = 0; j < width; j++)
     { IACA_START
      cfine[((1 << ((8 + 1) / 2)) *
	     ((width) * ((srcp[j]) >> ((8 + 1) / 2)) + (j)) +
	     ((srcp[j]) & ((1 << ((8 + 1) / 2)) - 1)))]++;
      ccoarse[((1 << ((8 + 1) / 2)) * (j) + ((srcp[j]) >> ((8 + 1) / 2)))]++;
} IACA_END }
