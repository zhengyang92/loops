#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (int pass, int i, const uint16_t * min_delta, int16_t * nlsf, int k,
    int order)
{
  int min_diff = 0;
  IACA_START for (i = 0; i < order + 1; i++)
    {
      int low = i != 0 ? nlsf[i - 1] : 0;
      int high = i != order ? nlsf[i] : 32768;
      int diff = (high - low) - (min_delta[i]);
      if (diff < min_diff)
	{
	  min_diff = diff;
	  k = i;
	  if (pass == 20)
	    break;
	}
     } IACA_END
}
