#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum CodingMode
{ CODING_MODE_RICE = 4, CODING_MODE_RICE2 = 5, };

typedef RiceContext;
typedef __uint64_t uint64_t;

int
fn (int exact, RiceContext * rc, int i, int opt_porder, int pmin, int n,
    int kmax, uint64_t bits[9], uint64_t (*sums)[256], int pmax,
    RiceContext tmp_rc, int pred_order)
{
  IACA_START for (i = pmax;;)
    {
      bits[i] =
	calc_optimal_rice_params (&tmp_rc, i, sums, n, pred_order, kmax,
				  exact);
      if (bits[i] < bits[opt_porder] || pmax == pmin)
	{
	  opt_porder = i;
	  *rc = tmp_rc;
	}
      if (i == pmin)
	break;
      calc_sum_next (--i, sums, exact ? kmax : 0);
     } IACA_END
}
