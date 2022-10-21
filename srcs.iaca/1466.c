#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;

int
fn (const INTFLOAT * const window, const int n2, int i, const int n,
    const int n4, INTFLOAT * saved, INTFLOAT * out, INTFLOAT * buf)
{
  for (i = 0; i < n2; i++)
     { IACA_START
      out[n4 + i] =
	(int) (((int64_t) (buf[i]) * (window[i + n2 - n4]) +
		0x40000000) >> 31) +
	(int) (((int64_t) (-saved[n - 1 - i]) * (window[i + n2 + n - n4]) +
		0x40000000) >> 31) +
	(int) (((int64_t) (-saved[n + i]) * (window[i + n2 + 2 * n - n4]) +
		0x40000000) >> 31) +
	(int) (((int64_t) (saved[2 * n + n - 1 - i]) *
		(window[i + n2 + 3 * n - n4]) + 0x40000000) >> 31);
} IACA_END }
