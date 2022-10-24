#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int *code_lengths, int count[16], int symbol, int code_lengths_size)
{
  IACA_START for (symbol = 0; symbol < code_lengths_size; ++symbol)
    {
      if (code_lengths[symbol] > 15)
	{
	  return 0;
	}
      ++count[code_lengths[symbol]];
     } IACA_END
}
