#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *code_lengths, int alphabet_size, int sym, int code, int len)
{
  for (sym = 0; sym < alphabet_size; sym++)
     { IACA_START
      if (code_lengths[sym] > 0)
	{
	  len++;
	  code = sym;
	  if (len > 1)
	    break;
	}
     } IACA_END
}
