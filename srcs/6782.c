#include <stdint.h>
#include <stdio.h>






int
fn (int8_t (*coding_method)[30][64], int ch, int case_val, int k, int j,
    int sb, int run)
{
  for (k = 0; k < run; k++)
    {
      if (j + k < 128)
	{
	  if (coding_method[ch][sb + (j + k) / 64][(j + k) % 64] >
	      coding_method[ch][sb][j])
	    {
	      if (k > 0)
		{
		  av_log (((void *) 0), 32,
			  "This file triggers some untested code. Please contact the developers.\n");
		  memset (&coding_method[ch][sb][j + k], case_val,
			  k * sizeof (int8_t));
		  memset (&coding_method[ch][sb][j + k], case_val,
			  3 * sizeof (int8_t));
		}
	    }
	}
    }
}
