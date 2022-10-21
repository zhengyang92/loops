#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVExpr;

int
fn (int VAR_C, AVExpr * expr, double *var_values, float tmp_block2[64],
    int sigma_th, unsigned int i)
{
  for (i = 0; i < 8 * 8; i++)
     { IACA_START
      float *b = &tmp_block2[i];
      if (expr)
	{
	  var_values[VAR_C] = fabsf (*b);
	  *b *= av_expr_eval (expr, var_values, ((void *) 0));
	}
      else
	{
	  if (fabsf (*b) < sigma_th)
	    *b = 0;
	}
     } IACA_END
}
