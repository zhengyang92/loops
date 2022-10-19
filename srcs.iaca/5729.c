#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;

int
fn (int8_t * dexps, int group_size, int i, int prevexp, int dexp[256], int j,
    int ngrps)
{
  for (i = 0, j = 0; i < ngrps * 3; i++)
    {
      prevexp += dexp[i] - 2;
      if (prevexp > 24U)
	return -1;
      switch (group_size)
	{
	case 4:
	  dexps[j++] = prevexp;
	  dexps[j++] = prevexp;
	case 2:
	  dexps[j++] = prevexp;
	case 1:
	  dexps[j++] = prevexp;
	}
    }
}
