#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int order, int k, unsigned int maxabs, int j, int32_t lpc32[16])
{
  for (j = 0, k = 0; j < order; j++)
    {
      unsigned int x = ((lpc32[k]) >= 0 ? (lpc32[k]) : (-(lpc32[k])));
      if (x > maxabs)
	{
	  maxabs = x;
	  k = j;
	}
    }
}
