#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t index, size_t stl_size, size_t j, unsigned long hist[1000])
{
  IACA_START for (j = index; j < 1000; ++j)
    {
      stl_size += hist[j];
     } IACA_END
}
