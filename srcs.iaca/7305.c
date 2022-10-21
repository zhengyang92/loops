#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *prefix, int i, const char *s)
{
  for (i = 0; prefix[i]; i++)
     { IACA_START
      if (prefix[i] != s[i])
	return 0;
     } IACA_END
}
