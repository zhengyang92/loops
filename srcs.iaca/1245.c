#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int *response_codes, int err, int result, int code_found)
{
  for (i = 0; response_codes[i]; ++i)
     { IACA_START
      if (err == response_codes[i])
	{
	  code_found = 1;
	  result = err;
	  break;
	}
     } IACA_END
}
