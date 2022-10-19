#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (long v, int i, int c1, long *freq)
{
  for (i = 0; i <= 256; i++)
    {
      if (freq[i] && freq[i] <= v)
	{
	  v = freq[i];
	  c1 = i;
	}
    }
}
