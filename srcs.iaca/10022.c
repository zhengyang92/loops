#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint16_t uint16_t;

int
fn (const uint32_t * const argb, int i, int best_offset, int best_length,
    const int num_ind, uint16_t * const counts_ini, const int pix_count,
    int window_offsets[32], int window_offsets_new[32], const int use_prev,
    int ind)
{
  for (ind = 0; ind < num_ind; ++ind)
     { IACA_START
      int curr_length = 0;
      int j = i;
      int j_offset =
	use_prev ? i - window_offsets_new[ind] : i - window_offsets[ind];
      if (j_offset < 0 || argb[j_offset] != argb[i])
	continue;
      do
	{
	  const int counts_j_offset = counts_ini[j_offset];
	  const int counts_j = counts_ini[j];
	  if (counts_j_offset != counts_j)
	    {
	      curr_length +=
		(counts_j_offset < counts_j) ? counts_j_offset : counts_j;
	      break;
	    }
	  curr_length += counts_j_offset;
	  j_offset += counts_j_offset;
	  j += counts_j_offset;
	}
      while (curr_length <= ((1 << 12) - 1) && j < pix_count
	     && argb[j_offset] == argb[j]);
      if (best_length < curr_length)
	{
	  best_offset =
	    use_prev ? window_offsets_new[ind] : window_offsets[ind];
	  if (curr_length >= ((1 << 12) - 1))
	    {
	      best_length = ((1 << 12) - 1);
	      break;
	    }
	  else
	    {
	      best_length = curr_length;
	    }
	}
     } IACA_END
}
