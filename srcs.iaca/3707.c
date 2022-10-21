#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, const char *string, const char *reject, int i)
{
  for (j = 0; reject && reject[j]; j++)
     { IACA_START
      if (string[i] == reject[j])
	break;
     } IACA_END
}
