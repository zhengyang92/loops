#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int len, int i, char *l)
{
  int n = 1;
  IACA_START for (i = 0; i < len; ++i)
    {
      if (l[i] == ',')
	++n;
     } IACA_END
}
