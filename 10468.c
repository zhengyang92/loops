#include <stdint.h>
#include <stdio.h>






int
fn (int j, int best, int i, unsigned char *bestloc, int n,
    unsigned char *data, unsigned char **hlist, int data_len)
{
  for (j = 0; j < n; ++j)
    {
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
    }
}
