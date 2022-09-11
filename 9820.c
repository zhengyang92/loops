#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;
typedef signed long tmsize_t;

int
fn (int rc, uint32 * tp, tmsize_t beg, tmsize_t npixels, tmsize_t i, uint32 b)
{
  int mask = 0;
  for (beg = i; beg < npixels; beg += rc)
    {
      b = tp[beg] & mask;
      rc = 1;
      while (rc < 127 + 2 && beg + rc < npixels && (tp[beg + rc] & mask) == b)
	rc++;
      if (rc >= 4)
	break;
    }
}
