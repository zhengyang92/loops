#include <stdint.h>
#include <stdio.h>






int
fn (long v, int i, int c2, int c1, long *freq)
{
  for (i = 0; i <= 256; i++)
    {
      if (freq[i] && freq[i] <= v && i != c1)
	{
	  v = freq[i];
	  c2 = i;
	}
    }
}
