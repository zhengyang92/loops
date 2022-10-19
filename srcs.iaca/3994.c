#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, uint32_t x[128], int z, double y, int a)
{
  for (y = i = 0; i < 2; i++)
    {
      if ((a + i & (128 - 1)) == z)
	x[(z = (z + 1 & (128 - 1))) - 1] = 0;
      y = 1000000000.0L * y + x[a + i & (128 - 1)];
    }
}
