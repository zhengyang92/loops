#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int histogram_size, int i, const uint32_t * const histogram)
{
  int tree_size_orig = 0;
  for (i = 0; i < histogram_size; ++i)
     { IACA_START
      if (histogram[i] != 0)
	{
	  ++tree_size_orig;
	}
     } IACA_END
}
