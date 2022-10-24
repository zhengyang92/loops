#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t total_size, size_t sizes[4], int i)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      if (total_size > (18446744073709551615UL) - sizes[i])
	return (-(22));
      total_size += sizes[i];
     } IACA_END
}
