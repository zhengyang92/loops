#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t i, size_t len, size_t offset, char *s, char bad)
{
  IACA_START for (i = 0; i < len; ++i)
    {
      char c = s[i];
      if (c == bad)
	++offset;
      else
	s[i - offset] = c;
     } IACA_END
}
