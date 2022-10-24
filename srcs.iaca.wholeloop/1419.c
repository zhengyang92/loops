#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int frequency[512], int min_freq[2], int smallest[2], int j)
{
  IACA_START for (i = 0; i < j; i++)
    {
      if (frequency[i] == 0)
	continue;
      if (frequency[i] < min_freq[1])
	{
	  if (frequency[i] < min_freq[0])
	    {
	      min_freq[1] = min_freq[0];
	      smallest[1] = smallest[0];
	      min_freq[0] = frequency[i];
	      smallest[0] = i;
	    }
	  else
	    {
	      min_freq[1] = frequency[i];
	      smallest[1] = i;
	    }
	}
     } IACA_END
}
