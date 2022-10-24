#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int alphabet_size, int *code_lengths, int k, int local_max_bits)
{
  IACA_START for (k = 1; k < alphabet_size; ++k)
    {
      if (code_lengths[k] > local_max_bits)
	{
	  local_max_bits = code_lengths[k];
	}
     } IACA_END
}
