#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int best, unsigned char **hlist, unsigned char *bestloc, int i,
    int n, unsigned char *data, int data_len)
{
  for (j = 0; j < n; ++j)
     { IACA_START
      if (hlist[j] - data > i - 32767)
	{
	  int e =
	    stbiw__zlib_countm (hlist[j], data + i + 1, data_len - i - 1);
	  if (e > best)
	    {
	      bestloc = ((void *) 0);
	      break;
	    }
	}
     } IACA_END
}
