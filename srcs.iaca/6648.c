#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t * basis, unsigned int sum, int16_t * rem, int16_t * weight,
    int scale)
{
  for (i = 0; i < 8 * 8; i++)
     { IACA_START
      int b = rem[i] + ((basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6));
      int w = weight[i];
      b >>= 6;
      ((-512 < b
	&& b < 512) ? (void) (0) : __assert_fail ("-512 < b && b < 512",
						  "program.c", 42,
						  __extension__
						  __PRETTY_FUNCTION__));
      sum += (w * b) * (w * b) >> 4;
} IACA_END }
