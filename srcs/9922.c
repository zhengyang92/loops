#include <stdint.h>
#include <stdio.h>






int
fn (const int *distribution, int k, int max_value)
{
  int last_non_zero = 0;
  for (k = 0; k <= 31; ++k)
    {
      const int value = distribution[k];
      if (value > 0)
	{
	  if (value > max_value)
	    max_value = value;
	  last_non_zero = k;
	}
    }
}
