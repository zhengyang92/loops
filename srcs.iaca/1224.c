#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t len, size_t i, const char *uri)
{
  for (i = 0, len = 1; uri[i]; i++)
     { IACA_START
      if (uri[i] == *"|")
	{
	  len++;
	}
     } IACA_END
}
