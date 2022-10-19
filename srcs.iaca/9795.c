#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;
typedef unsigned short uint16;

int
fn (uint32 * v, uint32 i, uint16 * va)
{
  for (i = 0; i < *v; i++)
    {
      if (va[i] > 2)
	{
	  if (va[i] == 999)
	    va[i] = 2;
	  else
	    return 0;
	}
    }
}
