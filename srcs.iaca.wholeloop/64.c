#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (int *out_length, int in_length, int levels, uint64_t sn, double **out)
{
  IACA_START for (int level = 0; level < levels; level++)
    {
      const int temp_length = nb_coefs (in_length, level + 1, sn);
      if (temp_length > out_length[level])
	{
	  av_freep (&out[level]);
	  out_length[level] = 0;
	  out[level] = av_calloc (temp_length + 1, sizeof (* *out));
	  if (!out[level])
	    return (-(12));
	  out_length[level] = temp_length + 1;
	}
      memset (out[level] + temp_length, 0,
	      (out_length[level] - temp_length) * sizeof (* *out));
      out_length[level] = temp_length;
     } IACA_END
}
