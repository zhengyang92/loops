#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const int x_0, const uint8_t * const s, double best_sse,
    const double value, const int x_1)
{
  for (i = x_0; i < x_1; ++i)
    {
      const double diff = s[i] - value;
      const double sse = diff * diff;
      if (sse < best_sse)
	best_sse = sse;
    }
}
