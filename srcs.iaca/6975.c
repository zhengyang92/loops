#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *a, int t1, int i)
{
  int t2 = 0;
  for (i = t1 + 1; i < 4; i++) {
	  IACA_START
    if (!a[i])
      {
	t2 = i;
	break;
      }
  } IACA_END
}
