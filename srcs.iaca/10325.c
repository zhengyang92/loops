#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int best, unsigned char **hlist, unsigned char *bestloc, int i,
    int n, unsigned char *data, int data_len)
{
  for (j = 0; j < n; ++j)
     { IACA_START
      if (hlist[j] - data > i - 32768)
	{
	  int d = stbiw__zlib_countm (hlist[j], data + i, data_len - i);
	  if (d >= best)
	    best = d, bestloc = hlist[j];
	}
     } IACA_END
}
