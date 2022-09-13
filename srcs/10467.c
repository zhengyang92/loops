#include <stdint.h>
#include <stdio.h>






int
fn (int j, int best, int i, unsigned char *bestloc, int n,
    unsigned char *data, unsigned char **hlist, int data_len)
{
  for (j = 0; j < n; ++j)
    {
      if (hlist[j] - data > i - 32768)
	{
	  int d = stbiw__zlib_countm (hlist[j], data + i, data_len - i);
	  if (d >= best)
	    best = d, bestloc = hlist[j];
	}
    }
}
