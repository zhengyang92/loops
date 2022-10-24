#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *a, int t1, int i)
{
  int t2 = 0;
  IACA_START for (i = t1 + 1; i < 4; i++)
    if (!a[i])
      {
	t2 = i;
	break;
      }
  IACA_END
}
