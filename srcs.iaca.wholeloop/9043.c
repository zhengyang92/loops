#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int *match_h_offset_ptr, int *match_len_ptr, const uint8_t * haystack,
    const uint8_t * needle, int h_pos, int *match_n_offset_ptr, int h_len,
    int n_len, int n_pos)
{
  IACA_START for (h_pos = 0; h_pos < h_len; h_pos++)
    {
      int match_len = 0;
      int match_h_pos, match_n_pos;
      while (h_pos + match_len < h_len && n_pos + match_len < n_len
	     && needle[n_pos + match_len] == haystack[h_pos + match_len])
	match_len++;
      if (match_len <= 8)
	continue;
      match_h_pos = h_pos;
      match_n_pos = n_pos;
      while (match_n_pos > 0 && match_h_pos > 0
	     && needle[match_n_pos - 1] == haystack[match_h_pos - 1])
	{
	  match_n_pos--;
	  match_h_pos--;
	  match_len++;
	}
      if (match_len <= 14)
	continue;
      *match_h_offset_ptr = match_h_pos;
      *match_n_offset_ptr = match_n_pos;
      *match_len_ptr = match_len;
      return 0;
     } IACA_END
}
