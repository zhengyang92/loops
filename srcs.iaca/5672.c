#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *buf, const int n2, float *out, float *saved, int i, const int n,
    const int n4, const float *const window)
{
  for (i = 0; i < n2; i++)
     { IACA_START
      out[n4 + i] =
	buf[i] * window[i + n2 - n4] + -saved[n - 1 - i] * window[i + n2 + n -
								  n4] +
	-saved[n + i] * window[i + n2 + 2 * n - n4] + saved[2 * n + n - 1 -
							    i] * window[i +
									n2 +
									3 *
									n -
									n4];
     } IACA_END
}
