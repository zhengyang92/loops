#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (int i, size_t sizes[4], int total_size)
{
  for (i = 0; i < 4; i++)
    {
      if (sizes[i] > 2147483647 - total_size)
	return (-(22));
      total_size += sizes[i];
    }
}
