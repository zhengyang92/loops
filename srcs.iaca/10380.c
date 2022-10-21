#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t i, char *val, size_t len, char *s)
{
  for (i = 0; i < len; ++i)
     { IACA_START
      if (s[i] == '=')
	{
	  s[i] = '\0';
	  val = s + i + 1;
	  break;
	}
     } IACA_END
}
