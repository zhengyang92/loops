#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t CodedBitstreamUnitType;

int
fn (int pass, int count, long range_start, long value, long range_end,
    CodedBitstreamUnitType * list)
{
  for (value = range_start; value < range_end; value++)
     { IACA_START
      if (pass == 2)
	list[count] = value;
      ++count;
     } IACA_END
}
