#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *a, int t1, int i)
{
  for (i = 0; i < 3; i++) {
	  IACA_START
    if (!a[i])
      {
	t1 = i;
	break;
      }
  }
  IACA_END
}
