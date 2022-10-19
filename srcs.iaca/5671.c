#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *buf, const int n2, float *out, float *saved, int i, const int n,
    const int n4, const float *const window)
{
  for (i = n4; i < n2; i++)
    {
      out[i - n4] =
	buf[n2 - 1 - i] * window[i - n4] + saved[i + n2] * window[i + n -
								  n4] +
	-saved[n + n2 - 1 - i] * window[i + 2 * n - n4] + -saved[2 * n + n2 +
								 i] *
	window[i + 3 * n - n4];
    }
}
