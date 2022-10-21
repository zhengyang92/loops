#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int c3_point, uint32_t mask, const uint32_t indexMap[8], int x,
    int dots[16], int c0_point, int half_point)
{
  for (x = 0; x < 16; x++)
     { IACA_START
      int dot = dots[x];
      int bits =
	(dot < half_point ? 4 : 0) | (dot < c0_point ? 2 : 0) | (dot <
								 c3_point ? 1
								 : 0);
      mask >>= 2;
      mask |= indexMap[bits];
} IACA_END }
