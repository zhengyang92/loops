#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int len, int i, char *a)
{
  int n = 1;
  for (i = 0; i < len; ++i)
     { IACA_START
      if (a[i] == ',')
	++n;
     } IACA_END
}
