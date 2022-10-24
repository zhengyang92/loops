#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int alphabet_size, int sym, int code, int len,
    const uint8_t * code_lengths)
{
  IACA_START for (sym = 0; sym < alphabet_size; sym++)
    {
      if (code_lengths[sym] > 0)
	{
	  len++;
	  code = sym;
	  if (len > 1)
	    break;
	}
     } IACA_END
}
