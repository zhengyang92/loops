#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (int j, int streams, size_t *offsets, size_t size)
{
  for (j = 0; j < streams; ++j)
     { IACA_START
      offsets[j] = rand_size_t () % size;
     } IACA_END
}
