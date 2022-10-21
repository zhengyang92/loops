#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum CodingMode
{ CODING_MODE_RICE = 4, CODING_MODE_RICE2 = 5, };

typedef RiceContext;
typedef __uint64_t uint64_t;

int
fn (int i, RiceContext * rc, int opt_porder, int pmin, int n,
    uint64_t bits[9], RiceContext tmp_rc, int pmax, uint64_t sums[9][256],
    int pred_order)
{
  for (i = pmin; i <= pmax; i++)
     { IACA_START
      bits[i] = calc_optimal_rice_params (&tmp_rc, i, sums[i], n, pred_order);
      if (bits[i] <= bits[opt_porder])
	{
	  opt_porder = i;
	  *rc = tmp_rc;
	}
     } IACA_END
}
