#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (const INTFLOAT * const window, const int n2, int i, const int n4,
    const int n, INTFLOAT * saved, INTFLOAT * out, INTFLOAT * buf)
{
  IACA_START for (i = n4; i < n2; i++)
    {
      out[i - n4] =
	((buf[n2 - 1 - i]) * (window[i - n4])) +
	((saved[i + n2]) * (window[i + n - n4])) +
	((-saved[n + n2 - 1 - i]) * (window[i + 2 * n - n4])) +
	((-saved[2 * n + n2 + i]) * (window[i + 3 * n - n4]));
     } IACA_END
}
