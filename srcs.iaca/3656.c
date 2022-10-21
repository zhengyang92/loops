#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * samples_l, int32_t * samples_r, int i, int32_t lor)
{
  int nb_samples = 0;
  int32_t diff = 0;
  for (i = 0; i < nb_samples; i++)
     { IACA_START
      lor |= samples_l[i] | samples_r[i];
      diff |= samples_l[i] - samples_r[i];
      if (lor && diff)
	break;
     } IACA_END
}
