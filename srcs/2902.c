#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int nCoeffs, int16_t * block, int qadd, int qmul, int level)
{
  for (i = 0; i <= nCoeffs; i++)
    {
      level = block[i];
      if (level)
	{
	  if (level < 0)
	    {
	      level = level * qmul - qadd;
	    }
	  else
	    {
	      level = level * qmul + qadd;
	    }
	  block[i] = level;
	}
    }
}
