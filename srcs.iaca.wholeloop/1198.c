#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *v, int k, int len)
{
  IACA_START for (k = 0; k < len; k += 8)
    {
      do
	{
	  float SWAP_tmp = v[k + 4];
	  v[k + 4] = v[k + 2];
	  v[k + 2] = SWAP_tmp;
	}
      while (0);
      do
	{
	  float SWAP_tmp = v[k + 5];
	  v[k + 5] = v[k + 3];
	  v[k + 3] = SWAP_tmp;
	}
      while (0);
     } IACA_END
}
