#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;
typedef signed short int16;

int
fn (int16 b, int rc, tmsize_t beg, tmsize_t npixels, tmsize_t i, int16 * tp)
{
  int mask = 0;
  for (beg = i; beg < npixels; beg += rc)
     { IACA_START
      b = (int16) (tp[beg] & mask);
      rc = 1;
      while (rc < 127 + 2 && beg + rc < npixels && (tp[beg + rc] & mask) == b)
	rc++;
      if (rc >= 4)
	break;
     } IACA_END
}
