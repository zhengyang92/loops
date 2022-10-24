#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (const INTFLOAT * const window, int i, const int n2, INTFLOAT * saved,
    const int n, const int n4, INTFLOAT * out, INTFLOAT * buf)
{
  IACA_START for (i = 0; i < n4; i++)
    {
      out[n2 + n4 + i] =
	((buf[i + n2]) * (window[i + n - n4])) +
	((-saved[n2 - 1 - i]) * (window[i + 2 * n - n4])) +
	((-saved[n + n2 + i]) * (window[i + 3 * n - n4]));
     } IACA_END
}
