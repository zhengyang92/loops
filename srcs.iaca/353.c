#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t c, size_t frames, size_t src_index, const double **srcs, size_t i,
    int stride)
{
  double max = 0.0;
  for (i = 0; i < frames; ++i)
     { IACA_START
      double v = srcs[c][src_index + i * stride];
      if (v > max)
	{
	  max = v;
	}
      else if (-v > max)
	{
	  max = -1.0 * v;
	}
     } IACA_END
}
