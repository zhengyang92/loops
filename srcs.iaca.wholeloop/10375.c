#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int len, int i, char *a)
{
  int n = 1;
  IACA_START for (i = 0; i < len; ++i)
    {
      if (a[i] == ',')
	++n;
     } IACA_END
}
