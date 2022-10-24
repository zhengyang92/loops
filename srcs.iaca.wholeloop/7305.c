#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *prefix, int i, const char *s)
{
  IACA_START for (i = 0; prefix[i]; i++)
    {
      if (prefix[i] != s[i])
	return 0;
     } IACA_END
}
