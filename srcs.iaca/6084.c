#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int8_t cavlc_level_tab[7][256][2], unsigned int i, int suffix_length)
{
  for (i = 0; i < (1 << 8); i++)
    {
      int prefix = 8 - (31 - __builtin_clz ((2 * i) | 1));
      if (prefix + 1 + suffix_length <= 8)
	{
	  int level_code =
	    (prefix << suffix_length) +
	    (i >> ((31 - __builtin_clz ((i) | 1)) - suffix_length)) -
	    (1 << suffix_length);
	  int mask = -(level_code & 1);
	  level_code = (((2 + level_code) >> 1) ^ mask) - mask;
	  cavlc_level_tab[suffix_length][i][0] = level_code;
	  cavlc_level_tab[suffix_length][i][1] = prefix + 1 + suffix_length;
	}
      else if (prefix + 1 <= 8)
	{
	  cavlc_level_tab[suffix_length][i][0] = prefix + 100;
	  cavlc_level_tab[suffix_length][i][1] = prefix + 1;
	}
      else
	{
	  cavlc_level_tab[suffix_length][i][0] = 8 + 100;
	  cavlc_level_tab[suffix_length][i][1] = 8;
	}
    }
}
