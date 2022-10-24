#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *coefs_ptr, float *decoder_standard_deviation, int j,
    int region)
{
  IACA_START for (j = 0; j < 20; j++)
    {
      if (*coefs_ptr != 0)
	{
	  i++;
	  if (fabs (*coefs_ptr) > 2.0 * decoder_standard_deviation[region])
	    {
	      i += 3;
	    }
	}
      coefs_ptr++;
     } IACA_END
}
