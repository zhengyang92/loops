#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int k, int16_t * index)
{
  for (k = 4; k < 6; k++)
    {
      if (index[k] >= 44 && index[k] < 108)
	{
	  index[k] += 64;
	}
      else if (index[k] >= 108 && index[k] < 128)
	{
	  index[k] += 128;
	}
    }
}
