#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *revtab, int k1, int offset, int inv_lookup, int k2, int even_idx,
    int n, int inv, int len, int odd_idx, int stride)
{
  for (int i = 0; i < len; i++)
     { IACA_START
      k1 = -split_radix_permutation (offset + i * 2 + 0, n, inv) & (n - 1);
      k2 = -split_radix_permutation (offset + i * 2 + 1, n, inv) & (n - 1);
      if (inv_lookup)
	{
	  revtab[even_idx++] = k1;
	  revtab[odd_idx++] = k2;
	}
      else
	{
	  revtab[k1] = even_idx++;
	  revtab[k2] = odd_idx++;
	}
      if (stride && !((i + 1) % stride))
	{
	  even_idx += stride;
	  odd_idx += stride;
	}
     } IACA_END
}
