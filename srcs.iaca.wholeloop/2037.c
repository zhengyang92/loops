#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t CodedBitstreamUnitType;

int
fn (int count, int pass, long range_start, long value, long range_end,
    CodedBitstreamUnitType * list)
{
  IACA_START for (value = range_start; value < range_end; value++)
    {
      if (pass == 2)
	list[count] = value;
      ++count;
     } IACA_END
}
