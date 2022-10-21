#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int code_lengths_size, uint16_t * sorted, int symbol, int offset[16],
    const int *code_lengths)
{
  for (symbol = 0; symbol < code_lengths_size; ++symbol)
     { IACA_START
      const int symbol_code_length = code_lengths[symbol];
      if (code_lengths[symbol] > 0)
	{
	  sorted[offset[symbol_code_length]++] = symbol;
	}
     } IACA_END
}
