#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *g, const float *Exp, const float *Ex, const float *Ep,
    float r[22])
{
  for (int i = 0; i < 22; i++)
     { IACA_START
      if (Exp[i] > g[i])
	r[i] = 1;
      else
	r[i] =
	  ((Exp[i]) * (Exp[i])) * (1 - ((g[i]) * (g[i]))) / (.001 +
							     ((g[i]) *
							      (g[i])) * (1 -
									 ((Exp
									   [i])
									  *
									  (Exp
									   [i]))));
      r[i] = sqrtf (av_clipf_sse (r[i], 0, 1));
      r[i] *= sqrtf (Ex[i] / (1e-8 + Ep[i]));
     } IACA_END
}
